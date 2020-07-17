package main

func stringCompression(input string) string  {
	count:=0
	output:=make([]rune,1)
	for itr, val := range input {
		if input[itr]==input[itr+1] {
			count++
			itr++
		}
		output=append(output,val+)


	}
}