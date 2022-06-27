class Node:
    def __init__(self, data: int):
        self.data = data
        self.linkprev = None
        self.linknext = None

    def getdata(self):
        return self.data

    def getprev(self):
        return self.linkprev

    def getnext(self):
        return self.linknext

    def setdata(self, data):
        self.data = data

    def setprev(self, linkprev):
        self.linkprev = linkprev

    def setnext(self, linknext):
        self.linknext = linknext


class Linkedlist:
    def __init__(self):
        self.head = Node(0)

    def is_empty(self):
        check = False
        if self.head is None:
            check = True
        return check

    def getsize(self):
        size = 0
        current = self.head
        while current is not None:
            size = size + 1
            current = current.getNext()
        return size

    def insert_at_begin(self, value: int):
        new_node = Node(value)
        current = self.head
        new_node.setnext(current)
        current.setprev(new_node)
        self.head = new_node

    def insert_at_end(self, value: int):
        current = self.head
        while current.getnext() is not None:
            current = current.getnext()
        new_node = Node(value)
        current.setnext(new_node)
        new_node.setprev(current)

    def insert_at_pos(self, value: int, position: int):
        current = self.head
        new_node = Node(value)
        pos = 0
        previous = None
        while pos < position:
            pos = pos + 1
            previous = current
            current = current.getnext()
        previous.setnext(new_node)
        new_node.setprev(previous)
        new_node.setnext(current)
        current.setprev(new_node)

    def delete_at_begin(self):
        current = self.head
        current = current.getnext()
        self.head = current

    def delete_at_end(self):
        current = self.head
        while current.getnext() is None:
            current = current.getnext()
        current = current.getprev()
        current.setnext(None)

    def delete_at_pos(self, position: int):
        current = self.head
        previous = None
        pos = 0
        if position == 1:
            self.delete_at_begin()
        if position == self.getsize():
            self.delete_at_end()
        while pos < position:
            pos = pos + 1
            previous = current
            current = current.getnext()
        tmp = current.getnext()
        previous.setnext(tmp)
        tmp.setprev(previous)

    def display(self):
        current = self.head
        while current is not None:
            print(current.getdata())
            current = current.getnext()

    def search_by_index(self, value: int) -> int:
        current = self.head
        count = 0
        found = False
        while current is not None and not found:
            count = count + 1
            if current.getdata() == value:
                found = True
            current = current.getnext()
        return count

    def search_by_value(self, value: int) -> bool:
        current = self.head
        found = False
        count = 0
        while current is None and not found:
            if current.getdata() == value:
                found = True
            else:
                count = count + 1
                current = current.getnext()
        return found

    def traverse_begin(self):
        self.display()

    def traverse_end(self):
        current = self.head
        while current.getnext() is not None:
            current = current.getnext()
        while current is not None:
            print(current.getdata())
            current = current.getnext()

    def update(self, value: int, position: int):
        current = self.head
        pos = 0
        while pos < position:
            pos = pos + 1
            current = current.getnext()

        current.setdata(value)


if __name__ == "__main__":
    print("Doubly lisnked list .")
    print("1. Insert at beginning .")
    print("2. Insert at end .")
    print("3. Insert at specify position .")
    print("4. Delete at beginning .")
    print("5. Delete at end .")
    print("6. Delete at specify position .")
    print("7. Traverse from begin .")
    print("8. Traverse from end .")
    print("9. Display doubly linked list .")
    print("10. Check empty .")
    print("11. Searching index of value in list .")
    print("12. Searching value in doubly linked list .")
    print("13. Update .")
    print("14. Exit .")
    list = Linkedlist()
    ck = True
    while(ck):
        choice = int(input("Enter the choice :"))
        if choice == 1:
            val = int(input("Enter the value to insert : "))
            list.insert_at_begin(val)
        elif choice == 2:
            val = int(input("Enter the value to insert : "))
            list.insert_at_end(val)
        elif choice == 3:
            val = int(input("Enter the the value to insert : "))
            pos = int(input("Enter the position :"))
            list.insert_at_pos(val,pos)
        elif choice == 4:
            list.delete_at_begin()
        elif choice == 5:
            list.delete_at_end()
        elif choice == 6:
            pos = int(input("Enter specify position to delete ."))
            list.delete_at_pos(pos)
        elif choice == 7:
            list.traverse_begin()
        elif choice == 8:
            list.traverse_end()
        elif choice == 9:
            list.display()
        elif choice == 10:
            print("Empty status : ",list.is_empty())
        elif choice == 11:
            value = int((input("Enter the value which want to search index : ")))
            print("Index of value in doubly linked list : ",list.search_by_index(value))
        elif choice == 12:
            value = int((input("Enter the value which want to search index : ")))
            print(list.search_by_value(value))
        elif choice == 13:
            value = int(input("Value to update :"))
            pos = int(input("Position which need update value ."))
            list.update()
        elif choice == 14:
            ck = False

