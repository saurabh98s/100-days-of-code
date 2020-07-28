package main

import (
	"errors"
	"fmt")


type node struct {
	data int
	next *node
}

type linkedList struct {
	name string
	head *node
}

func createLinkedList(name string) *linkedList {
	return &linkedList{
		name: name,
	}
}

func (ll *linkedList) addNode(data int) error {
	node := &node{
		data: data,
	}
	if ll.head == nil {
		ll.head = node
	} else {
		node.next = ll.head
		ll.head = node
	}
	return nil
}

func (ll *linkedList) print() error {
	currentSong := ll.head
	if currentSong == nil {
		return errors.New("[ERROR] No nodes to display")
	}
	for currentSong.next !=nil {
		fmt.Println(currentSong.data)
		currentSong=currentSong.next
		
	}
	return nil

}


func (ll *linkedList) checkForDups(){
	checkMap:=make(map[int]bool)
	previous:=ll.head
	for ll.head != nil {
		if checkMap[ll.head.data] {
			previous.next=ll.head.next
		} else {
			checkMap[ll.head.data]=true
			previous=ll.head
		}
		ll.head=ll.head.next

	}
}

func main()  {
	myLinkedList:="mylist"
	mylist:=createLinkedList(myLinkedList)
	fmt.Println("Created a linked list")
	mylist.addNode(1)
	mylist.addNode(2)
	for i := 0; i < 10; i++ {
		mylist.addNode(i)
	}
	fmt.Println("checking for dups")
	mylist.checkForDups()
	mylist.print()
}