import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class DateClient {
    public static void main(String[] args) {
        try {
            //connect to the server at 6013 port number
            Socket socket=new Socket("127.0.0.1", 6013);

            //create BufferedReaader to read from the socket
            BufferedReader input =new BufferedReader(
                new InputStreamReader(socket.getInputStream())
            );

            //Read and print Servers response
            String serverdate=input.readLine();
            System.out.println("Server Date: " + serverdate);

            //close the connection
            socket.close();
        } catch (IOException e) {
            System.err.println("Error: " + e);
        }
    }   
}
