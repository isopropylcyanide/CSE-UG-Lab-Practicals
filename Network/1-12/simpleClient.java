import java.util.*;
import java.io.*;
import java.net.*;

// Client program to send a string to a server and print the output

class simpleClient{
    public static void main(String[] args) throws IOException{
        String sentence;

        try{
            System.out.print("Enter string for server: ");
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            sentence = in.readLine();

            Socket clientSock = new Socket("localhost",25000);
            DataOutputStream outToServer = new  DataOutputStream(clientSock.getOutputStream());
            BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSock.getInputStream()));

            outToServer.writeBytes(sentence + "\n");
            String reversedSent = inFromServer.readLine();
            System.out.println("Received from server : " + reversedSent);
            clientSock.close();
        }
        catch (IOException e){
            System.out.println("IO Exception caught at client");
        }
    }
}
