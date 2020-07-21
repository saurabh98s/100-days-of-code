#include<iostream>

using namespace std;

struct song
{
    string name;
    string artist;
    song* previous;
    song* next;

};

struct playlist
{
    string name;
    song* start;
    song* end;
    song* nowPlaying;
    
};



playlist* createPlaylist(string name) {

    playlist* temp = new playlist();
    temp->name=name;
    return temp;
}

void addSongEnd(string name,string artist, playlist* p) {

    song* newSong = new song();
    newSong->name=name;
    newSong->artist=artist;
    if (p->start==NULL)
    {
        p->start=newSong;
    } else {
        song* currentSong = new song();
        currentSong=p->end;
        currentSong->next=newSong;
        newSong->previous=p->end;
    }
    p->end=newSong;

}

void showAllSongs(playlist* p) {
    song* currentSong = new song();
    if (currentSong==NULL)
    {
        cout<<"No songs to show";
    }
    cout<<"%s",currentSong->name;
    for (;;)
    {
        if (currentSong->next!=NULL)
        {
            cout<<currentSong->name;
            currentSong=currentSong->next;
        } else
        {
            cout<<"end of playlist";
            break;
        }
    }
}

int main() {

    string playListName= "myplaylist";
    playlist* myplaylist= new playlist();
    myplaylist=createPlaylist(playListName);
    addSongEnd("ShapeOfYou","ed Sheeran",myplaylist);
    showAllSongs(myplaylist);


}