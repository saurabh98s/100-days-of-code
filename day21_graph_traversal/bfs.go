package main


//Node type holds the data required fro DFS
type Node struct {

	name string
	children []*Node

}

// BFS traverse along the graph keeping a depth first approach
func (node *Node) BFS(array []string) []string {
	// append the node which we touched first
	queue:=[]*Node{node}

	for len(queue)>0 {
		// store queue front value in current
		current:=queue[0]
		// remove front value from queue
		queue=queue[1:]
		array=append(array, current.name)
		for _, childNode := range current.children {
			queue = append(queue, childNode)
		}
	}

	return array
	
}