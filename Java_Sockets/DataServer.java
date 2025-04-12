import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class DataServer {
    public static void main(String[] args) {
        try{
            ServerSocket sock=new ServerSocket(6013);
            System.out.println("Data Server is running on port 6013..");

            //listen to the connection
            while(true){
                Socket client=sock.accept();

            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
