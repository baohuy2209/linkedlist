package main 
import (
	"fmt"
	"math/rand"
	"errors"
)

type Node struct {
	value int 
	next *Node 
}

func add(list *Node, data int) {
	if list == nil {
		list := new(Node)
		list.value = data 
		list.next = nil 

	}else{
		temp := new(Node) 
		temp.value = data 
		temp.next = list 
	}
}

func display(list *Node) {
	var temp *Node 
	temp = list 
	for temp != nil{
		fmt.Println(temp.value)
		temp = temp.next 
	}
}

func insert(list *Node, data int, position){
	if position == 1 {
		add(list,data)
	}
	else{
		var pos int 
		pos = 0 
		pre = nil 
		for pos < position{
			pos = pos + 1 
			pre = list 
			list = list.next
		}
		temp := new(Node)
		pre.next = temp 
		temp.next = list  
	}
}

func remove(list *Node, data int){
	cur = list 
	pre = nil 
	var found bool
	found = false 
	for list != nil && !found{
		if (list.value == data){
			found = true 
		}else{
			pre = cur 
			cur = cur.next 
		}
	}
	if (found){
		if (pre == nil){
			list = cur.next
		}else{
			pre.next = cur.next  
		}
	}else{
		err := errors.New("Invalid")
		fmt.Println(err)
	}
}

func pop(list *Node, position int){
	if position > size(list){
		err := errors.New("Invalid")
		fmt.Println(err)
	}else{
		cur = list
		pre = nil 
		for pos < position{
			pos = pos + 1
			pre = cur  
			cur = cur.next 
		}
		var ret *Node 
		ret = cur.value 
		pre.next = cur.next
	}
	return ret 
}

func size(list *Node) int{
	cur = list 
	var size int 
	size = 0 
	for cur != nil{
		size = size + 1 
		cur = cur.next 
	}
	return size 
}

func search(list *Node, item int) bool{
	if (list == nil){
		fmt.Println("Not found .")
	}
	var ck bool 
	ck = false 
	for list != nil &&  !ck{
		if (list.value == item){
			ck = true 
		}else{
			list = list.next
		}
	}
	return ck 
}

func checkempty(list *Node) bool{
	return list == nil 
}

func searchindex(list *Node, item int) {
	cur = list 
	var found bool 
	found = false
	index = 0  
	for cur != nil && !found {
		if (cur.value == item){
			found = true 
		}else{
			index = index + 1 
			cur = cur.next 
		}
	}
	if (found){
		fmt.Println(index)
	}else{
		fmt.Println("Invalid")
	}
} 


func printlist(list *Node){
	for list != nil {
		fmt.Println(list)
		list = list.next 
	}
}
