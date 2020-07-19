package main

import (
	"errors"
	"fmt"
)

type playlist struct { //say this is a link list
	name string
	start *song
	nowPlaying *song
}

type song struct { //this is a node
	name string
	artist string
	next *song //points to the next song
}


func createPlaylist(name string) *playlist {
	return &playlist{
		name: name,
	}
}

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

func (p *playlist) showAllSongs() error  {
	currentSong:=p.start
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

func (p *playlist) startPlaying() *song  {
	p.nowPlaying=p.start
	return p.nowPlaying
}

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