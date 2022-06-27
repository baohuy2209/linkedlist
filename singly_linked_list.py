class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

    def getdata(self):
        return self.data

    def setdata(self, value):
        self.data = value

    def getnext(self):
        return self.next

    def setnext(self, linknext):
        self.next = linknext


class Linkedlist:
    def __init__(self):
        self.head = Node(0)

    def insert_at_begin(self, value: int):
        current = self.head
        new_node = Node(value)
        new_node.setnext(current)
        self.head = new_node

    def insert_at_end(self, value: int):
        current = self.head
        new_node = Node(value)
        while current.getnext() is not None:
            current = current.getnext()
        current.setnext(new_node)

    def insert_at_pos(self, value: int, position: int):
        pos = 0
        current = self.head
        new_node = Node(value)
        previous = None
        while pos < position:
            pos = pos + 1
            previous = current
            current = current.getnext()
        previous.setnext(new_node)
        new_node.setnext(current)

    def delete_at_pos(self, position: int):
        current = self.head
        if position == 1:
            current = current.getnext()
            self.head = current
        if position == self.getsize():
            while current.getnext().getnext() is None:
                current = current.getnext()
            current.setnext(None)

        pos = 0
        pre = None
        while pos < position:
            pos = pos + 1
            pre = current
            current = current.getnext()
        tmp = current.getnext()
        pre.setnext(tmp)

    def display(self):
        current = self.head
        while current is not None:
            print(current.getdata() + " ")
            current = current.getnext()

    def update(self, value: int, position: int):
        current = self.head
        pos = 0
        while pos < position:
            pos = pos + 1
            current = current.getnext()
        current.setdata(value)

    def search(self, value: int) -> int:
        current = self.head
        found = False
        count = 0
        while current is not None and not found:
            if value == current.getdata():
                found = True
            else:
                current = current.getnext()
                count = count + 1
        return count

    def checkempty(self) -> bool:
        check = False
        if self.head is None:
            check = True
        return check

    def getsize(self) -> int:
        size = 0
        current = self.head
        while current is not None:
            size = size + 1
            current = current.getnext()

        return size


if __name__ == "__main__":
    print("Singy linked list operation .")
    print("1. Insert at beginning .")
    print("2. Insert at end .")
    print("3. Insert at specify position .")
    print("4. Delete at position .")
    print("5. Update value at position .")
    print("6. Search value in singly linked list and return its index .")
    print("7. Check empty .")
    print("8. Get size of the doubly linked list .")
    print("9. Display .")
    print("10. Exit .")
    ck = True
    list = Linkedlist()
    while(ck):
        choice = int(input("Enter the choice : "))
        if choice == 1:
            val = int(input("Enter the value : "))
            list.insert_at_begin(val)
        elif choice == 2:
            val = int(input("Enter the value : "))
            list.insert_at_end(val)
        elif choice == 3:
            val = int(input("Enter the value : "))
            pos = int(input("Enter the position to insert value :"))
            if pos < 1 or pos > list.getsize():
                raise Exception("Invalid")
            list.insert_at_pos(val, pos)
        elif choice == 4:
            pos = int(input("Enter the position to insert value :"))
            if pos < 1 or pos > list.getsize():
                raise Exception("Invalid")
            list.delete_at_pos(pos)
        elif choice == 5:
            value = int(input("Enter the value to update : "))
            pos = int(input("Enter the position to insert value :"))
            if pos < 1 or pos > list.getsize():
                raise Exception("Invalid")
            list.update(value, pos)
        elif choice == 6:
            value = int(input("Enter the value to search : "))
            print("Position of value : ",list.search(value))
        elif choice == 7:
            print("Empty status = ",list.checkempty())
        elif choice == 8:
            print("Size of doubly linked list : ",list.getsize())
        elif choice == 9:
            list.display()
        elif choice == 10:
            ck = False
        
