import java.io.*;
import java.net.*;

class UDPClient 
{
	public static void main(String args[]) throws Exception
	{
		byte[] rData=new byte[1024];
		byte[] sData=new byte[1024];

		String msg="";

		DatagramSocket cs=new DatagramSocket();
		sData=msg.getBytes();

		InetAddress IP=InetAddress.getByName("localhost");

		DatagramPacket sPacket=new DatagramPacket(sData,sData.length,IP,9876);
		cs.send(sPacket);

		DatagramPacket rPacket=new DatagramPacket(rData,rData.length);
		cs.receive(rPacket);

		msg=new String(rPacket.getData());

		System.out.println("The Message is "+msg);

		cs.close();
	}
}