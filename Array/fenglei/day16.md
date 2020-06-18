```
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```



### C++

```c++
struct Node {
    char data;
    struct Node *next;

    Node(char c) : data(c), next(NULL) {}
};


bool isValid(char *s) {
    Node *n = new Node('0');
    size_t len = strlen(s);
    if (len %2 != 0){
        return false;
    }
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            Node *n1 = new Node(c);
            n1->next = n;
            n = n1;
        } else if (c == ')' || c == '}' || c == ']') {
            char r = n->data;
            if ((r == '(' && c == ')') || (r == '{' && c == '}') || ((r == '[' && c == ']'))) {
                n = n->next;
            }
        }
    }
    return n->next == NULL;
}

int main() {
    bool flag = isValid("([)]");
    printf("result:%d", flag);
    return 0;
}
```



### JAVA

```java

    public boolean isValid (String s) {
        Node node = new Node('0');
        int len = s.length();
        if (len % 2 != 0) return false;
        for (int i = 0; i < len; ++i) {
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                Node n1 = new Node(c);
                n1.next = node;
                node = n1;
            } else if (c == ')' || c == '}' || c == ']') {
                char r = node.data;
                if ((r == '(' && c == ')') || (r == '{' && c == '}') || ((r == '[' && c == ']'))) {
                    node = node.next;
                }
            }
        }
        return node.next == null;
    }

    class Node {
        char data;
        Node next;

        public Node (char data) {
            this.data = data;
            this.next = null;
        }
    }

```



### Kotlin

```ko

    fun isValid(s: String): Boolean {
        var node = Node('0')
        val len = s.length
        if (len % 2 == 0) return false;
        for (c in s) {
            if (c == '(' || c == '{' || c == '[') {
                var n1 = Node(c)
                n1.next = node
                node = n1
            } else if (c == ')' || c == '}' || c == ']') {
                var r = node.value
                if ((r == '(' && c == ')') || (r == '{' && c == '}') || ((r == '[' && c == ']'))) {
                    node = node.next!!
                }
            }
        }
        return node.next == null
    }

    class Node(var value: Char) {
        var next: Node? = null
        init {
            this.next = null
        }
    }
```

