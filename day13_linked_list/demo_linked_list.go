package main

import (
	"errors"
	"fmt"
)

type playlist struct { //say this is a linked list
	name string //name of the playlist
	start *song //first song
	end *song //last song of the playlist
	nowPlaying *song //current song
}

type song struct { //this is a node
	name string //name of the song
	artist string //name of the artist
	previous *song //points to the previous song
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
		fmt.Println(s.name)
		p.start=s
	} else {
		fmt.Println(s.name)
		currentSong:= p.end //the starting song of the playlist
		currentSong.next=s										//where the next song value is nil	 
		s.previous=p.end
	}
	p.end=s //new song appended at the end
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
func(p *playlist) previousSong() *song {
	p.nowPlaying=p.nowPlaying.previous
	return p.nowPlaying
}

func (p *playlist) addSongAfterASong(name string, prevSong *song) error  {
	songToBeAdded:=&song{
		name: name,
	}
	if prevSong ==nil {
		return errors.New("[ERROR] The prevoius Node cant be NULL")
	}
	songToBeAdded.next=prevSong.next
	prevSong.next=songToBeAdded
	return nil
	
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
	myPlaylist.previousSong()
	fmt.Println("Changing previous song...")
	fmt.Printf("Now playing: %s by %s\n", myPlaylist.nowPlaying.name, myPlaylist.nowPlaying.artist)
	fmt.Println()
	myPlaylist.previousSong()
	fmt.Println("Changing previous song...")
	fmt.Printf("Now playing: %s by %s\n", myPlaylist.nowPlaying.name, myPlaylist.nowPlaying.artist)
	myPlaylist.addSongAfterASong("Kal ho na ho",myPlaylist.start.next)
	myPlaylist.showAllSongs()
	fmt.Println()

}