​																	kotlin 高洁函数和Lambda

1、高阶函数怎么用：

函数类型可以像数据类型一样，既可以用于定义变量，也可以用于函数的形参类型，还可以做为返回数值。

做形参类型：

fun k1（data：Int，name：String）{
}

做返回数值：

fun k2（data：Int，name：String）->String{

​	return "aaaa";

}

Kotlin 提供了简洁的 Lambda 表达式语法。

var result ={

​	执行语句

}（参数列表）

主要作用使用点：

1、替代局部函数

2、省略形参名称

3、可以在任意圆括号外进行编写

4、不确定参数个数

动态权限获取：

```kotlin
class PermissionUtils(private val context: Activity) {

    private var mHasPermissionRunnable: Runnable? = null
    private var mNoPermissionRunnable: Runnable? = null
    private var REQUEST_CODE_PERMISSION = 1000

    fun checkStoragePermission(hasPermissionDo: Runnable) {
        var permission = arrayOf(Manifest.permission.READ_EXTERNAL_STORAGE)
        checkPermission(permission, hasPermissionDo, Runnable {
            context.showPermissionDialog("不开启存储权限，无法访问相册哦~")
        })
    }

    fun checkCameraPermission(hasPermissionDo: Runnable) {
        var permission = arrayOf(Manifest.permission.CAMERA, Manifest.permission.WRITE_EXTERNAL_STORAGE)
        checkPermission(permission, hasPermissionDo, Runnable {
            context.showPermissionDialog("不开启相机权限，无法拍照哦~")
        })
    }

    fun checkPermission(permissions: Array<out String>, hasPermissionDo: Runnable, noPermissionDo: Runnable) {
        mHasPermissionRunnable = null
        mNoPermissionRunnable = null
        if (isPermissionsGranted(permissions)) hasPermissionDo.run()
        else if (ActivityCompat.shouldShowRequestPermissionRationale(context, permissions.get(0))) {
            noPermissionDo.run()
        } else {
            mHasPermissionRunnable = hasPermissionDo
            mNoPermissionRunnable = noPermissionDo
            ActivityCompat.requestPermissions(context, permissions, REQUEST_CODE_PERMISSION)
        }
    }


     fun isPermissionsGranted(permissions: Array<out String>): Boolean {
        for (it in permissions) {
            if (ContextCompat.checkSelfPermission(context, it) != PackageManager.PERMISSION_GRANTED)
                return false
        }
        return true
    }

    private fun isAllGranted(grantResults: IntArray): Boolean {
        for (it in grantResults) {
            if (it != PackageManager.PERMISSION_GRANTED) return false
        }
        return true
    }

    fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        if (requestCode == REQUEST_CODE_PERMISSION) {
            if (isAllGranted(grantResults))
                mHasPermissionRunnable?.run()
            else mNoPermissionRunnable?.run()
        }
    }
```

