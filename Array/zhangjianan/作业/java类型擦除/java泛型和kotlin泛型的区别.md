#### kotlin的泛型的类型投影和java的通配符

Array<out T>`相当于 Java 中的`Array<? extends T>`，而`Array<in T>`相当于 Java 中的`Array<? super T>`，out 表示生产，用于只读类型，in 表示消费，用于只写类型。