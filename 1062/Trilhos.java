import java.util.Scanner;

public class Trilhos{

	static Stck newTrain(int size){
		Stck ret = new Stck();
		for(int i=size; i>=1; i--){
			ret.push(i);
		}
		return ret;
	}

	static boolean check(int[] wanted){
		Stck incoming = newTrain(wanted.length);
			
		Stck station = new Stck();
		for(int i=0; i<wanted.length; i++){
			int wnt = wanted[i];
			boolean search = true;
			while(search){
				if(station.top == null) station.push(incoming.pop());
				else if(station.top.data == wnt){
					search = false;
					station.pop();
				}
				else if(incoming.top != null) station.push(incoming.pop());
				else return false;
			}
		}
		return true;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String in = sc.nextLine();
		while(!in.equals("0")){
			in = sc.nextLine();
			while(!in.equals("0")){
				String[] sep = in.split(" ");
				int[] arr = new int[sep.length];
				for(int i=0; i<sep.length; i++) arr[i] = Integer.parseInt(sep[i]);
				if(check(arr)) System.out.println("Yes");
				else System.out.println("No");
				in = sc.nextLine();
			}
			System.out.println("");
			in = sc.nextLine();
		}
	}

}

class Cell{
	public int data;
	public Cell next;

	Cell(){
		this.data = 0;
		this.next = null;
	}

	Cell(int x){
		this.data = x;
		this.next = null;
	}
}

class Stck{
	public Cell top;

	Stck(){
		this.top = null;
	}

	public void push(int x){
		Cell tmp = new Cell(x);
		tmp.next = this.top;
		this.top = tmp;
	}

	public int pop(){
		int ret = this.top.data;
		Cell tmp = this.top;
		this.top = this.top.next;
		tmp.next = null;
		return ret;
	}
}
		
