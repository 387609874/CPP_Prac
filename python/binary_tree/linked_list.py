class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList(object):
    def __init__(self, list=[]):
        self.head = None
        for i in list:
            self.push_back(i)

    def push_back(self, data):
        node = Node(data)
        # if linked list is empty
        if self.head == None:
            self.head = node
        else:
            curNode = self.head
            # find the last node of the liked list
            while curNode.next != None:
                curNode = curNode.next
            curNode.next = node

    def printList(self):
        curNode = self.head
        linked_list = []
        while curNode != None:
            linked_list.append(curNode.data)
            curNode = curNode.next
        print linked_list


    def insert(self, data, pos=0):
        node = Node(data)
        # if linked list is empty
        if self.head == None:
            self.head = node
        else:
            # insert to the beginning of the list
            if pos == 0:
                tempNode = self.head
                self.head = node
                self.head.next = tempNode
            else:
                curNode = self.head
                nextNode = self.head
                done = False
                for i in range(1, pos):
                    curNode = curNode.next
                    nextNode = curNode.next
                    # if pos is greater than the size of linked list,
                    # insert in the end.
                    if nextNode == None:
                        curNode = node
                        done = True
                # insert node to the pos
                if done == False:
                    curNode.next = node
                    node.next = nextNode

    def remove(self, pos):
        # If the list is empty
        if self.head == None:
            print "Remove failed. The list is empty."
        elif self.head.next == None and pos == 0:
            # list only have one item
            self.head = None
        else:
            curNode = self.head
            nextNode = self.head
            # Traversal though list
            for i in range(1, pos):
                curNode = curNode.nextNode
                nextNode = curNode.nextNode
                # if pos is too large
                if nextNode == None and i != pos -1:
                    print "Unable to remove item"
                # if pos is larger than ght size of the list
                elif nextNode == None and i == pos - 1:
                    curNode = None
            # remove nextNode
            curNode.next = nextNode.next

if __name__ == '__main__':
    myList = LinkedList([1,2,3,4,5,6,7,8])
    myList.printList()