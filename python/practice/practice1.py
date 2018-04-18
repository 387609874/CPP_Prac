'''
    This is a list of test case follow by expected results
'''
testcase1 = [["udacity", "ad", True],
             ["potato", "td", False],
             ["chicken fry", "fy", True],
             ["chicken fry", "fz", False]]
def question1(s, t):
    '''
        Question 1
        Given two strings s and t, determine whether some anagram of t is a substring of s. For example: if s = "udacity" and t = "ad", then the function returns True. Your function definition should look like: question1(s, t) and return a boolean True or False.
    '''
    size = len(t)
    for i in range(0, size):
        if t[i] not in s:
            return False
    return True

def test1(testcase):
    '''
        this function will test question 1 function.
    '''
    testpass = True
    for i in testcase:
        if question1(i[0], i[1]) != i[2]:
            testpass = False
            print "test failed in " + i[0] + " " + i[1]
    if testpass == True:
        print "All test passed"

def isPalindrom(s):
    # reserve a string takes O(n)
    if s == s[::-1]:
        return True
    else:
        return False

def  question2(s):
    longest = ""
    longestLength = len(longest)
    size = len(s)
    # this algrithms will take O(n^3)
    for i in range(0, size):
        for j in range(size, i, -1):
            k = s[i:j]
            l = len(k)
            if isPalindrom(k) and l > longestLength:
                longest = k
                longestLength = l
    return longest


class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

testcase5 = Node(0);

def createLinkList(ll):
    curNode = ll;
    for i in range(1,10):
        newNode = Node(i)
        curNode.next = newNode
        curNode = curNode.next


def question5(ll, m):
    curNode = ll
    if m < 0:
        print str(m) + " can not be less than 0."
    for i in range(0, m):
        if curNode == None:
            print str(m) + " is greater than the size of lined list"
            return None
        curNode = curNode.next
    print str(m) + "th node is " + str(curNode.data)
    return curNode.data

def test5(testcase):
    createLinkList(testcase5)
    for i in range(0, 5):
        question5(testcase5, i)
    question5(testcase5, 100)
    question5(testcase5, -1)






#test1(testcase1)
#test5(testcase5)

print "the longest is \"" + question2("jjujhijkhkjh") +"\""