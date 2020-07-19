package main

import (
	"errors"
	"fmt"
)

type playlist struct { //say this is a link list
	name string //name of the playlist
	start *song //first song
	nowPlaying *song //current song
}

type song struct { //this is a node
	name string //name of the song
	artist string //name of the artist
	next *song //points to the next song
}

// createPlaylist creates a new playlist and returns the playlist
func createPlaylist(name string) *playlist {
	return &playlist{
		name: name,
	}
}

// addsong to the playlist at the end of the playlist if there are already some songs
func (p *playlist)addSong(name string,artist string) error  {
	s:=&song{
		name: name,
		artist: artist,
	}
	if p.start ==nil {
		p.start=s
	} else {
		currentNode:= p.start //the starting song of the playlist
		for currentNode.next !=nil {
			currentNode=currentNode.next //shift the next pointer till the last song 
		} //where the next song value is nil
		currentNode.next=s //then assign the song to the next pointer
	}
	return nil
}
// showAllSongs shows all the songs in the playlist
func (p *playlist) showAllSongs() error  {
	currentSong:=p.start //currentSong
	if currentSong ==nil {
		err:=errors.New("No song in the playlist")
		return	err
	}
	fmt.Printf("%#v\n",currentSong)
	for currentSong.next!=nil{
		currentSong=currentSong.next
		fmt.Println(currentSong.name)
	}
	return nil
}

// startPlaying shows the first song of the playlist
func (p *playlist) startPlaying() *song  {
	p.nowPlaying=p.start
	return p.nowPlaying
}
// nextSong shifts the pointer to the next song in the playlist
func (p *playlist) nextSong() *song  {
	p.nowPlaying=p.nowPlaying.next
	return p.nowPlaying
}


func main() {
	playlistName := "myplaylist"
	myPlaylist := createPlaylist(playlistName)
	fmt.Println("Created playlist")
	fmt.Println()
	fmt.Print("Adding songs to the playlist...\n\n")
	myPlaylist.addSong("Ophelia", "The Lumineers")
	myPlaylist.addSong("Shape of you", "Ed Sheeran")
	myPlaylist.addSong("Stubborn Love", "The Lumineers")
	myPlaylist.addSong("Feels", "Calvin Harris")
	fmt.Println("Showing all songs in playlist...")
	myPlaylist.showAllSongs()
	fmt.Println()
	myPlaylist.startPlaying()
	fmt.Printf("Now playing: %s by %s\n", myPlaylist.nowPlaying.name, myPlaylist.nowPlaying.artist)
	fmt.Println()
	myPlaylist.nextSong()
	fmt.Println("Changing next song...")
	fmt.Printf("Now playing: %s by %s\n", myPlaylist.nowPlaying.name, myPlaylist.nowPlaying.artist)
	fmt.Println()
	myPlaylist.nextSong()
	fmt.Println("Changing next song...")
	fmt.Printf("Now playing: %s by %s\n", myPlaylist.nowPlaying.name, myPlaylist.nowPlaying.artist)
}