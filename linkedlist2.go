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
		var pre *Node
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
	var cur *Node
	cur = list 
	var pre *Node 
	pre = nil 
	var found bool
	found = false 
	for cur != nil && !found{
		if (cur.value == data){
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

		var cur *Node
		cur = list
		var pre *Node
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
	var cur *Node 
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
	var cur *Node 
	cur = list 
	if (cur == nil){
		fmt.Println("Not found .")
	}
	var ck bool 
	ck = false 
	for cur != nil &&  !ck{
		if (cur.value == item){
			ck = true 
		}else{
			cur = cur.next
		}
	}
	return ck 
}

func checkempty(list *Node) bool{
	var cur *Node 
	return cur == nil 
}

func searchindex(list *Node, item int) {
	var cur *Node
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
	var cur *Node 
	cur  = list 
	for cur != nil {
		fmt.Println(cur)
		cur = cur.next 
	}
}
