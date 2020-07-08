### HashMap 分析

##### 常量

```java
  	/**
     *默认初始容量必须为 2 的整数幂(Q: 为什么初始容量必须为 2 的整数幂？)
     */
    static final int DEFAULT_INITIAL_CAPACITY = 1 << 4;

		// 容量的最大值
		static final int MAXIMUM_CAPACITY = 1 << 30;

		// 容量的负载因子，当超过时将扩容（Q:为什么负载因子为 0.75f？）
		static final float DEFAULT_LOAD_FACTOR = 0.75f;
			
		// 链表转换为树的阈值，当超过这个阈值后链表变为红黑树
		static final int TREEIFY_THRESHOLD = 8;
		
		// 树转换为链表的阈值，当少于这个阈值后树当链表处理
		static final int UNTREEIFY_THRESHOLD = 6;
		
		// 树的最小容量
		static final int MIN_TREEIFY_CAPACITY = 64;
```



##### 构造方法

```java
  
		public HashMap(int initialCapacity, float loadFactor) {
        if (initialCapacity < 0)
            throw new IllegalArgumentException("Illegal initial capacity: " +
                                               initialCapacity);
        if (initialCapacity > MAXIMUM_CAPACITY)
            initialCapacity = MAXIMUM_CAPACITY;
        if (loadFactor <= 0 || Float.isNaN(loadFactor))
            throw new IllegalArgumentException("Illegal load factor: " +
                                               loadFactor);
        this.loadFactor = loadFactor;
				// 初始化容量
        this.threshold = tableSizeFor(initialCapacity);
    }
		
	  // 调用第一个构造方法传入设置好的容量和默认的负载因子
    public HashMap(int initialCapacity) {
        this(initialCapacity, DEFAULT_LOAD_FACTOR);
    }
		// 设置默认的负载因子 0.75
    public HashMap() {
        this.loadFactor = DEFAULT_LOAD_FACTOR; // all other fields defaulted
    }
		
		// 批量添加
    public HashMap(Map<? extends K, ? extends V> m) {
        this.loadFactor = DEFAULT_LOAD_FACTOR;
        putMapEntries(m, false);
    }
```

```java
    // 取大于等于这个值最大的 2 的整数幂
    static final int tableSizeFor(int cap) {
        int n = cap - 1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
    }

		// 批量加入数据
    final void putMapEntries(Map<? extends K, ? extends V> m, boolean evict) {
				// 获取需要添加数据的 size
        int s = m.size();
        if (s > 0) {
            if (table == null) { // pre-size
              	// 计算需要用到的容量
                float ft = ((float)s / loadFactor) + 1.0F;
                int t = ((ft < (float)MAXIMUM_CAPACITY) ?
                         (int)ft : MAXIMUM_CAPACITY);
              	// 如果大于扩容阈值 threshold 为扩容阈值
                if (t > threshold)
                    threshold = tableSizeFor(t);
            }
          	// 如果超出当前 hashmap 大小则扩容
            else if (s > threshold)
                resize();
          	// 遍历数据加入 map
            for (Map.Entry<? extends K, ? extends V> e : m.entrySet()) {
                K key = e.getKey();
                V value = e.getValue();
                putVal(hash(key), key, value, false, evict);
            }
        }
    }
```

##### 数据操作相关的方法

* 扩容 resize()

```java
    final Node<K,V>[] resize() {
      	// 保存当前 hash 表
        Node<K,V>[] oldTab = table;
      	// 获取当前表的长度
        int oldCap = (oldTab == null) ? 0 : oldTab.length;
      	// 保存需要调整大小的值
        int oldThr = threshold;
      	// 声明扩容的大小和扩容的阈值
        int newCap, newThr = 0;
        if (oldCap > 0) {
          	// 如果当前容量已经达到了最大值，就不能扩容了直接返回 oldTab
            if (oldCap >= MAXIMUM_CAPACITY) {
                threshold = Integer.MAX_VALUE;
                return oldTab;
            }
          	// 把当前的值扩大一倍如果在合理的区间内则扩大一倍
            else if ((newCap = oldCap << 1) < MAXIMUM_CAPACITY &&
                     oldCap >= DEFAULT_INITIAL_CAPACITY)
                newThr = oldThr << 1; // double threshold
        }
      	// 如果之前有需要扩容的大小则直接设置
        else if (oldThr > 0) // initial capacity was placed in threshold
            newCap = oldThr;
        else {               // zero initial threshold signifies using defaults
            // 如果没有之前扩容的数据则设置默认容量，以及默认的扩容阈值
          	newCap = DEFAULT_INITIAL_CAPACITY;
            newThr = (int)(DEFAULT_LOAD_FACTOR * DEFAULT_INITIAL_CAPACITY);
        }
      	// 如果扩容阈值为 0，则根据当前的容量和负载因子计算当前的扩容阈值
        if (newThr == 0) {
            float ft = (float)newCap * loadFactor;
            newThr = (newCap < MAXIMUM_CAPACITY && ft < (float)MAXIMUM_CAPACITY ?
                      (int)ft : Integer.MAX_VALUE);
        }
      	// 更新扩容的阈值
        threshold = newThr;
        // 构建一个容量为 newCap 的容器把 tab 存进去
        @SuppressWarnings({"rawtypes","unchecked"})
            Node<K,V>[] newTab = (Node<K,V>[])new Node[newCap];
        table = newTab;
        if (oldTab != null) {
            for (int j = 0; j < oldCap; ++j) {
                Node<K,V> e;
              	// 如果之前的表不等于有数据 清空旧表数据，并把旧表数据加入到新表
                if ((e = oldTab[j]) != null) {
                    oldTab[j] = null;
                    if (e.next == null)
                        newTab[e.hash & (newCap - 1)] = e;
                    else if (e instanceof TreeNode)
                      	// 如果旧表是红黑树
                        ((TreeNode<K,V>)e).split(this, newTab, j, oldCap);
                    else { 
                      	// 如果旧表示链表
                        Node<K,V> loHead = null, loTail = null;
                        Node<K,V> hiHead = null, hiTail = null;
                        Node<K,V> next;
                        do {
                            next = e.next;
                            if ((e.hash & oldCap) == 0) {
                                if (loTail == null)
                                    loHead = e;
                                else
                                    loTail.next = e;
                                loTail = e;
                            }
                            else {
                                if (hiTail == null)
                                    hiHead = e;
                                else
                                    hiTail.next = e;
                                hiTail = e;
                            }
                        } while ((e = next) != null);
                        if (loTail != null) {
                            loTail.next = null;
                            newTab[j] = loHead;
                        }
                        if (hiTail != null) {
                            hiTail.next = null;
                            newTab[j + oldCap] = hiHead;
                        }
                    }
                }
            }
        }
        return newTab;
    }
```

* 插入数据

```java
		// 实质调用的是 putVal(int hash, K key, V value, boolean onlyIfAbsent, boolean evict)
		public V put(K key, V value) {
    		return putVal(hash(key), key, value, false, true);
		}

    final V putVal(int hash, K key, V value, boolean onlyIfAbsent,
                   boolean evict) {
        Node<K,V>[] tab; Node<K,V> p; int n, i;
      	// 如果当前 table 为空做一次扩容
        if ((tab = table) == null || (n = tab.length) == 0)
            n = (tab = resize()).length;
      	//  获取 hash 找到 key 所在的位置，如果为空创建一个新的 node
        if ((p = tab[i = (n - 1) & hash]) == null)
            tab[i] = newNode(hash, key, value, null);
        else {     	
            Node<K,V> e; K k;
          	// 如果当前的 hash，key 和传入的相同则直接更新 node
            if (p.hash == hash &&
                ((k = p.key) == key || (key != null && key.equals(k))))
                e = p;
          	// 如果当前的 node 为红黑树，则直接相应的红黑树插入操作
            else if (p instanceof TreeNode)
                e = ((TreeNode<K,V>)p).putTreeVal(this, tab, hash, key, value);
            else {
              	// 遍历当前链表
                for (int binCount = 0; ; ++binCount) {
                  	// 如果没找到符号条件的 node 创建新的 node 添加到当前链表最后
                    if ((e = p.next) == null) {
                        p.next = newNode(hash, key, value, null);
                      	// 判断链表是否转为红黑树
                        if (binCount >= TREEIFY_THRESHOLD - 1) // -1 for 1st
                            treeifyBin(tab, hash);
                        break;
                    }
                  	// 如果找到了 跳出循环更新链表
                    if (e.hash == hash &&
                        ((k = e.key) == key || (key != null && key.equals(k))))
                        break;
                    p = e;
                }
            }
          	// 更新当前的链表并返回 oldValue
            if (e != null) { // existing mapping for key
                V oldValue = e.value;
                if (!onlyIfAbsent || oldValue == null)
                    e.value = value;
                afterNodeAccess(e);
                return oldValue;
            }
        }
      	// 判断是需要扩容操作
        ++modCount;
        if (++size > threshold)
            resize();
        afterNodeInsertion(evict);
        return null;
    }

		// 根据 key 生成对应的 hash
    static final int hash(Object key) {
        int h;
        return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
    }



				// 插入树的数据
        final TreeNode<K,V> putTreeVal(HashMap<K,V> map, Node<K,V>[] tab,
                                       int h, K k, V v) {
            Class<?> kc = null;
            boolean searched = false;
            TreeNode<K,V> root = (parent != null) ? root() : this;
          	//  遍历树
            for (TreeNode<K,V> p = root;;) {
                int dir, ph; K pk;
                if ((ph = p.hash) > h)
                    dir = -1;
                else if (ph < h)
                    dir = 1;
              	// 如果 key 相等返回当前节点
                else if ((pk = p.key) == k || (k != null && k.equals(pk)))
                    return p;
                else if ((kc == null &&
                          (kc = comparableClassFor(k)) == null) ||
                         (dir = compareComparables(kc, k, pk)) == 0) {
                    if (!searched) {
                      	// 根据 hash 值判断 q 为左子树还是右子树
                        TreeNode<K,V> q, ch;
                        searched = true;
                        if (((ch = p.left) != null &&
                             (q = ch.find(h, k, kc)) != null) ||
                            ((ch = p.right) != null &&
                             (q = ch.find(h, k, kc)) != null))
                            return q;
                    }
                    dir = tieBreakOrder(k, pk);
                }

                TreeNode<K,V> xp = p;
                if ((p = (dir <= 0) ? p.left : p.right) == null) {
                    Node<K,V> xpn = xp.next;
                    TreeNode<K,V> x = map.newTreeNode(h, k, v, xpn);
                    if (dir <= 0)
                        xp.left = x;
                    else
                        xp.right = x;
                    xp.next = x;
                    x.parent = x.prev = xp;
                    if (xpn != null)
                        ((TreeNode<K,V>)xpn).prev = x;
                    moveRootToFront(tab, balanceInsertion(root, x));
                    return null;
                }
            }
        }

```

* 获取数据

```java
    public V get(Object key) {
        Node<K,V> e;
        return (e = getNode(hash(key), key)) == null ? null : e.value;
    }
	
    final Node<K,V> getNode(int hash, Object key) {
        Node<K,V>[] tab; Node<K,V> first, e; int n; K k;
        if ((tab = table) != null && (n = tab.length) > 0 &&
            (first = tab[(n - 1) & hash]) != null) {
          	// 先检查第一个 node
            if (first.hash == hash && // always check first node
                ((k = first.key) == key || (key != null && key.equals(k))))
                return first;
          	// 遍历之后的 node
            if ((e = first.next) != null) {
              	// 如果为红黑树，在树种查找
                if (first instanceof TreeNode)
                    return ((TreeNode<K,V>)first).getTreeNode(hash, key);
                do {
                  	// 找到符合条件的返回
                    if (e.hash == hash &&
                        ((k = e.key) == key || (key != null && key.equals(k))))
                        return e;
                } while ((e = e.next) != null);
            }
        }
      	// 如果当前链表为 null，或者长度为 0，或者没有对应的 key 返回 null
        return null;
    }


		// 查找树节点
    final TreeNode<K,V> getTreeNode(int h, Object k) {
       return ((parent != null) ? root() : this).find(h, k, null);
    }
			
        final TreeNode<K,V> find(int h, Object k, Class<?> kc) {
          	// 从根节点开始查找如果大于查找右树 小于查找左树
            TreeNode<K,V> p = this;
            do {
                int ph, dir; K pk;
                TreeNode<K,V> pl = p.left, pr = p.right, q;
                if ((ph = p.hash) > h)
                    p = pl;
                else if (ph < h)
                    p = pr;
                else if ((pk = p.key) == k || (k != null && k.equals(pk)))
                    return p;
                else if (pl == null)
                    p = pr;
                else if (pr == null)
                    p = pl;
                else if ((kc != null ||
                          (kc = comparableClassFor(k)) != null) &&
                         (dir = compareComparables(kc, k, pk)) != 0)
                    p = (dir < 0) ? pl : pr;
                else if ((q = pr.find(h, k, kc)) != null)
                    return q;
                else
                    p = pl;
            } while (p != null);
            return null;
        }
```

* 删除数据

```java
    public V remove(Object key) {
        Node<K,V> e;
        return (e = removeNode(hash(key), key, null, false, true)) == null ?
            null : e.value;
    }

    final Node<K,V> removeNode(int hash, Object key, Object value,
                               boolean matchValue, boolean movable) {
        Node<K,V>[] tab; Node<K,V> p; int n, index;
      	 // 判断对应的 table 是否为 null
        if ((tab = table) != null && (n = tab.length) > 0 &&
            (p = tab[index = (n - 1) & hash]) != null) {
            Node<K,V> node = null, e; K k; V v;
          	// 判断第一个值是不是对应的 key 是的话就赋值给 node
            if (p.hash == hash &&
                ((k = p.key) == key || (key != null && key.equals(k))))
                node = p;
            else if ((e = p.next) != null) {
              	// 判断当前的 node 是红黑树还是链表
                if (p instanceof TreeNode)
                    node = ((TreeNode<K,V>)p).getTreeNode(hash, key);
                else {
                  	// 如果是链表就在链表中寻找对应对应的 key 
                    do {
                        if (e.hash == hash &&
                            ((k = e.key) == key ||
                             (key != null && key.equals(k)))) {
                            node = e;
                            break;
                        }
                        p = e;
                    } while ((e = e.next) != null);
                }
            }
          	// 移除 node 节点
            if (node != null && (!matchValue || (v = node.value) == value ||
                                 (value != null && value.equals(v)))) {
              	// 判断是否是红黑树如果是的话就移除树的节点
                if (node instanceof TreeNode)
                    ((TreeNode<K,V>)node).removeTreeNode(this, tab, movable);
                // 如果 node 在当前链表的第一个则直接移除
              	else if (node == p)
                    tab[index] = node.next;
              	// 如果 node 不在第一个删除 node
                else
                    p.next = node.next;
                ++modCount;
                --size;
              	// 空实现不知道有什么用
                afterNodeRemoval(node);
                return node;
            }
        }
        return null;
    }
```

* 链表转红黑树

```java
    final void treeifyBin(Node<K,V>[] tab, int hash) {
        int n, index; Node<K,V> e;
        // 如果没有达到阈值则进行扩容操作
      	if (tab == null || (n = tab.length) < MIN_TREEIFY_CAPACITY)
            resize();
      	// 满足条件则把每个节点都转化成 TreeNode
        else if ((e = tab[index = (n - 1) & hash]) != null) {
            TreeNode<K,V> hd = null, tl = null;
            do {
                TreeNode<K,V> p = replacementTreeNode(e, null);
                if (tl == null)
                    hd = p;
                else {
                    p.prev = tl;
                    tl.next = p;
                }
                tl = p;
            } while ((e = e.next) != null);
            if ((tab[index] = hd) != null)
              	// 构建红黑树
                hd.treeify(tab);
        }
    }

				// 链表转树
        final void treeify(Node<K,V>[] tab) {
            TreeNode<K,V> root = null;
            for (TreeNode<K,V> x = this, next; x != null; x = next) {
                next = (TreeNode<K,V>)x.next;
                x.left = x.right = null;
              	 // 构建树的根节点
                if (root == null) {
                    x.parent = null;
                    x.red = false;
                    root = x;
                }
                else {
                    K k = x.key;
                    int h = x.hash;
                    Class<?> kc = null;
                    for (TreeNode<K,V> p = root;;) {
                        int dir, ph;
                        K pk = p.key;
                      	// 遍历整个 TreeNode 比较 hash 的大小来确定存入左树还是右树
                        if ((ph = p.hash) > h)
                            dir = -1;
                        else if (ph < h)
                            dir = 1;
                        else if ((kc == null &&
                                  (kc = comparableClassFor(k)) == null) ||
                                 (dir = compareComparables(kc, k, pk)) == 0)
                            dir = tieBreakOrder(k, pk);

                        TreeNode<K,V> xp = p;
                        if ((p = (dir <= 0) ? p.left : p.right) == null) {
                            x.parent = xp;
                            if (dir <= 0)
                                xp.left = x;
                            else
                                xp.right = x;
                            root = balanceInsertion(root, x);
                            break;
                        }
                    }
                }
            }
            moveRootToFront(tab, root);
        }

```

