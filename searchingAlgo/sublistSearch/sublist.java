package searchingAlgo.sublistSearch;

class Node {
	int data;
	String sdata;
	Node next;
	Node(int d) {
        data = d;
        next = null;
    }
}

public class sublist {
	public static boolean sublistSearch(Node subList, Node list) {
		if(subList == null && list == null) {
			return true;
		}else if (subList == null || (subList != null && list == null)) { 
	        return false;
		}
		
		Node curr1 = subList;
		Node curr2 = list;
		
		while(list != null) {
			curr2 = list;
			while(curr1 != null) {
				if (curr2 == null) {
					return false;
				}
				if (curr1.data == curr2.data) {
					curr1 = curr1.next;
					curr2 = curr2.next;
				}else {
					break;
				}
				
				
			}
			if (curr1 == null) {
				return true;
			}
			curr1 = subList;
			list = list.next;

		}
		return false;
		
		
	}
	
	public static void main(String[] args) {
		Node subList1 = new Node(1);
		subList1.next = new Node(2);
		
		Node subList2 = new Node(2);
		subList2.next = new Node(3);
		
		Node list = new Node(1);
		list.next = new Node(2);
		list.next.next = new Node(4);
		
		System.out.println(sublistSearch(subList1,list));
		System.out.println(sublistSearch(subList2,list));

				
	}
}
