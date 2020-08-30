package main


//Node type holds the data required fro DFS
type Node struct {

	name string
	children []*Node

}

// DFS traverse along the graph keeping a depth first approach
func (node *Node) DFS(array []string) []string {
	// append the node which we touched first
	array=append(array, node.name)

	// loop through the children recursively and visit each node
	// and append them to the array
	for _, childNodes := range node.children {
		array= childNodes.DFS(array)
	}

	return array
	
}