import java.io.*;
import java.net.*;

class TCPServer {
    public static void main(String args) throws Exception
    {
        String s;
        ServerSocket ss1=new ServerSocket(80);

        while (true) 
        {
            Socket s1=ss1.accept();
            String dayOfTheWeek[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};    
            int i=(int)(Math.random()*dayOfTheWeek.length);
            s=dayOfTheWeek[i];
            PrintStream d1=new PrintStream(s1.getOutputStream());
            d1.println(s);
        }
    }
}