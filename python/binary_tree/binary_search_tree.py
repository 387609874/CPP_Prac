class Node(object):
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

class BinarySearchTree(object):
    '''
        CONSTRUCTOR
    '''
    def __init__(self, list):
        self.root = None
        # recursively insert all item in the lilst
        for i in list:
            if self.root == None:
                self.root = Node(i)
            else:
                self.insert(self.root, i)

    '''
        PUBLIC FUNCTIONS
    '''
    def insert(self,parent, data):
        if parent.left == None and data < parent.data:
            parent.left = Node(data)
        elif parent.right == None and data > parent.data:
            parent.right = Node(data)
        elif parent.left != None and data <= parent.data:
            self.insert(parent.left, data)
        elif parent.right != None and data >= parent.data:
            self.insert(parent.right, data)
        else:
            print "should not get here."

    def printTree(self):
        inOrder = []
        self.__inOrderTraversal(self.root, inOrder)
        print inOrder

    def traversal(self, tra="inOrder"):
        traversalList = []
        if tra == "inOrder":
            self.__inOrderTraversal(self.root, traversalList)
        elif tra == "preOrder":
            self.__preOrderTraversal(self.root, traversalList)
        elif tra == "postOrder":
            self.__postOrderTraversal(self.root, traversalList)
        else:
            print "The input suppose to be \"inOrder\", \"preOrder\", \"postOrder\""
        return traversalList

    def getLeftChild(self):
        return self.__getLeftChild(self.root)

    def getRightChild(self):
        return self.__getRightChild(self.root)

    '''
        PRIVATE FUNCTIONS
    '''
    def __inOrderTraversal(self, parent, inOrder):
        '''
            left, root, right
        '''
        if parent.left != None:
            self.__inOrderTraversal(parent.left, inOrder)
        inOrder.append(parent.data)
        if parent.right != None:
            self.__inOrderTraversal(parent.right, inOrder)

    def __preOrderTraversal(self, parent, preOrder):
        '''
            root, left, right
        '''
        preOrder.append(parent.data)
        if parent.left != None:
            self.__preOrderTraversal(parent.left, preOrder)
        if parent.right != None:
            self.__preOrderTraversal(parent.right, preOrder)

    def __postOrderTraversal(self, parent, postOrder):
        '''
            left, right, root
        '''
        if parent.left != None:
            self.__postOrderTraversal(parent.left, postOrder)
        if parent.right != None:
            self.__postOrderTraversal(parent.right, postOrder)
        postOrder.append(parent.data)


    def __getLeftChild(self, parent):
        if parent.left == None:
            return parent.data
        else:
            return self.__getLeftChild(parent.left)

    def __getRightChild(self, parent):
        if parent.right == None:
            return parent.data
        else:
            return self.__getRightChild(parent.right)

'''
    dictionary stores testing data
'''
testcase = [
    {
        "input": [1, 2, 3, 4, 5, 6, 7, 8, 9],
        "left_child": 1,
        "right_child": 9,
        "in_order_traversal": [1, 2, 3, 4, 5, 6, 7, 8, 9],
        "pre_order_traversal": [1, 2, 3, 4, 5, 6, 7, 8, 9],
        "post_order_traversal": [9, 8, 7, 6, 5, 4, 3, 2, 1]
    },
    {
        "input": [5, 4, 6, 3, 7, 2, 8, 1, 9],
        "left_child": 1,
        "right_child": 9,
        "in_order_traversal": [1, 2, 3, 4, 5, 6, 7, 8, 9],
        "pre_order_traversal": [5,4,3,2,1,6,7,8,9],
        "post_order_traversal": [1,2,3,4,9,8,7,6,5]
    }
]

def test(testcase):
    '''
        each test will have a list with 5 bolleans. They are representing each
        function of binary tree class. The order is
            result[0]: getLeftChild,
            result[1]: getRightChild,
            result[2]: traversal("inorder")
            result[3]: traversal("preOrder")
            result[4]: traversal("postOrder")
        This fucntion will return a list of lists
    '''
    testResults =[]
    for t in testcase:
        testR = []
        bTree = BinarySearchTree(t["input"])
        if bTree.getLeftChild() != t["left_child"]:
            testR.append(False)
        else:
            testR.append(True)
        if bTree.getRightChild() != t["right_child"]:
            testR.append(False)
        else:
            testR.append(True)
        if bTree.traversal() != t["in_order_traversal"]:
            testR.append(False)
        else:
            testR.append(True)
        if bTree.traversal("preOrder") != t["pre_order_traversal"]:
            testR.append(False)
        else:
            testR.append(True)
        if bTree.traversal("postOrder") != t["post_order_traversal"]:
            print bTree.traversal("postOrder"), t["post_order_traversal"]
            testR.append(False)
        else:
            testR.append(True)
        testResults.append(testR)
    return testResults

if __name__ == '__main__':
    '''
        testing code
    '''
    testPass = True
    result = test(testcase)

    for i in result:
        for b in i:
            if b == False:
                testPass = False
    if testPass == True:
        print "All test passed!"
    else:
        print "Some or all of tests failed, please check"
