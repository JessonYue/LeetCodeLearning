import java.io.IOException;

/***
 * AIDL也好，还是说binder或者是接口调用 往往设计是最难的。设计一个interface springboot 微服务
 */
public interface Server {

        void start() throws IOException;

        void register(Class serviceInterface, Class impl);

        boolean isRunning();

        int getPort();

        void stop();

//        public interface Event {
//                int eventresult(String code);
//        }
}
