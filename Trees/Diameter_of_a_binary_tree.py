
class Node:

	# Constructor to create a new node
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None



def height(node):

	# Base Case : Tree is empty
	if node is None:
		return 0

	return 1 + max(height(node.left), height(node.right))

# Function to get the diameter of a binary tree


def diameter(root):

	# Base Case when tree is empty
	if root is None:
		return 0

	# Get the height of left and right sub-trees
	lheight = height(root.left)
	rheight = height(root.right)

	# Get the diameter of left and right sub-trees
	ldiameter = diameter(root.left)
	rdiameter = diameter(root.right)

	return max(lheight + rheight + 1, max(ldiameter, rdiameter))


# Driver Code
if __name__ == "__main__":
	"""
	Constructed binary tree is
				1
			/ \
			2	 3
		/ \
		4	 5
	"""

	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)

	# Function Call
	print(diameter(root))

