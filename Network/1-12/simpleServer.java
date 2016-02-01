import java.util.*;
import java.io.*;
import java.net.*;

// Server program to receive a string from client and send it's reverse

class simpleServer{
    public static void main(String[] args) {
        String clientString, outString;
        try{
            ServerSocket serSock = new ServerSocket(25000);

            while (true){

                Socket conn = serSock.accept();
                BufferedReader inFromClient = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                DataOutputStream outToClient = new DataOutputStream(conn.getOutputStream());
                clientString = inFromClient.readLine();

                System.out.println("New message from client : "+ clientString);
                StringBuilder sb = new StringBuilder(clientString);

                outString = sb.reverse().toString();
                System.out.println("Sending reverse to client: "+ outString);
                outToClient.writeBytes(outString);
                conn.close();
            }

        }
        catch (IOException e){
            System.out.println("I/O Exception caught at server");
        }
    }
}
