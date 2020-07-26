package main


type Node struct {
	data int
	next *Node

}

type  LinkedList struct {
	head *Node
}



func (ll *LinkedList)insertNode(head *Node,data int)  {
		node:=&Node{
			data: data,
		}
		if ll.head==nil {
			ll.head=node
		} else{
			if ll.head!=nil {
					
			}
		}
}