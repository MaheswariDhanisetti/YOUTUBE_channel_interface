
#include <bits/stdc++.h>
using namespace std;

class Youtube
{
public:

    map<string , string>channels;
    int subscribers;

public:

    string ChannelName, OwnerName,Joindate;
    int views;
    Youtube(string channel, string owner,string jd,int sub,int vw)
    {
        ChannelName = channel;
        OwnerName = owner;
        Joindate=jd;
        subscribers=sub;
        views=vw;

    }


    // adding channel
    void addchannel()
    {
        channels[ChannelName]=OwnerName;
    }

    
    
};

class Channel : public Youtube
{
private:
    map<string,vector<string>>playlists;
    vector<string>videos;

public:


    Channel(string Cname, string Oname,string join,int sub,int vw) : Youtube(Cname, Oname,join,sub,vw) {
    
    }
    

    // adding videos to videos vector
    void addvideo(string video)
    {
        videos.push_back(video);
    }

    // displaying vidoes list
    void videodata()
    {
        cout<<"Videos : "<<endl;
        for(int i=0;i<videos.size();i++){
            cout<<"-"<<videos[i]<<endl;
        }
        cout<<endl;
    }

    // adding playlists 
    void addplaylist(string plname)
    {
        playlists[plname]=vector<string>(); //creates an empty playlist

    }

    // adding videos to playlist
    void addvideostoplaylist(string plname,string videoname)
    {
        // checking wheteher the playlist exist or not
        auto it=playlists.find(plname);

        // if the playlist exist
        if(it != playlists.end())
        {

            // checking whether the videoname exists in the videos vector
            auto vit = find(videos.begin(), videos.end(), videoname);
            

            // if the video exists
            if(vit != videos.end()){
                playlists[plname].push_back(videoname);
            }

            // if video doesn't exist
            else{
                cout<<" The vidoe "<<videoname<<" doesn't exist in "<<ChannelName<<" channel "<<endl;
                cout<<endl;
            }
        }

        // if playlist doesn't exist
        else{
            cout<<" The playlist "<<plname<<" doesn't exist in "<<ChannelName<<" channel "<<endl;
            cout<<endl;
        }
    }

    

    // displaying playlist
    void playlistdata(){

        cout<<"\nPlaylists : "<<endl;

        map<string, vector<string>>::iterator it;
        for(auto it : playlists)
        {
            cout<<"\n  Playlist Name :"<<it.first<<endl;
    
            vector<string>videos = it.second;

            // if playlist in not empty
            if(!videos.empty()){
              cout<<"  videos :"<<endl;
              for(int i=0;i<videos.size();i++){
                cout<<"  -"<<videos[i]<<endl;
              }
            }

            // if playlist is empty
            else{
                cout<<" This playlist is empty "<<endl;
            }

            cout<<endl;

        }
    } 
    

    // displaying channel data
    void channeldata()
    {
        cout<<"\n --- CHANNEL --- "<<endl;
        cout << "\nChannel Name :" << ChannelName << endl;
        cout << "Owner Name :" << OwnerName << endl;
        cout<<"Joined "<<Joindate<<endl;
        cout<<subscribers<<" Subscribers"<<endl;
        cout<<views<<" Views "<<endl;
        cout<<"videos count : "<<videos.size()<<endl;
        cout<<"playlists count : "<<playlists.size()<<endl;
        cout << endl;
    }
};

class user
{
    string username;
    vector<string>subscriptions;

public:

    user(string uname){
        username=uname;
    }


   void addsubscriptions(string ch){
    subscriptions.push_back(ch);
   } 


   // displaying userdata
   void userdata(){
    cout<<"\n --- USER ---\n "<<endl;
    cout<<"User Name: "<<username<<endl;
   }

   // displaying subscriptions data
   void subscriptionsdata(){
    cout<<"Subscriptions :"<<subscriptions.size()<<endl;
    for(int i=0;i<subscriptions.size();i++){
        cout<<subscriptions[i]<<endl;
    }
    cout<<endl;
   }

   // adding current channel to subscriptions
   void subscribeto(Channel &c1,int x){

    if(x == 1){
    // checking if already a subscriber or not
    if(find(subscriptions.begin(),subscriptions.end(),c1.ChannelName) == subscriptions.end()){
        subscriptions.push_back(c1.ChannelName); //added to subscriptions
        c1.subscribers=c1.subscribers+1; //increasing subscibers count for channel
        cout<<"subscribed to "<<c1.ChannelName<<" channel "<<endl;
        cout<<endl;
    }
    else{
        cout<<"You are already a subscriber to "<<c1.ChannelName<<" channel "<<endl;
        cout<<endl;
    }
   }
   }


   // removing channel from subscriptions
   void unsubscribeto(Channel &c2,int x){

    if(x == 2){

    if(find(subscriptions.begin(),subscriptions.end(),c2.ChannelName) == subscriptions.end()){
        cout<<"You are Not a subscriber to "<<c2.ChannelName<<" channel "<<endl<<endl;
    }
    else{
        // removed from subscriptions
        subscriptions.erase(find(subscriptions.begin(),subscriptions.end(),c2.ChannelName));
        c2.subscribers=c2.subscribers-1; //decreasing subscribers count for channel
        cout<<" unsubscribed to "<<c2.ChannelName<<" channel "<<endl<<endl;

    }
    }
   }


   
};

int main()
{
   

   // channel
    Channel c1("Jenny Lectures", "Jenny","21-09-2020",120000,1277788);
    Channel c2("Code with Harry", "Harrry","16-04-2019",50000,34567);
    Channel c3("Code Camp", "peter","28-01-2021",170000,96724);
    

    // adding channels
    c1.addchannel();
    c2.addchannel();
    c3.addchannel();


    // adding videos to videos vector
    c1.addvideo("Introduction");
    c1.addvideo("0-1 Knapsack");
    c1.addvideo("Kruskal's Algorithm");
    c1.addvideo("Longest Common Subsequences");

    //creating playlists
    c1.addplaylist("competitive Coding");

    // adding videos to playlist
    c1.addvideostoplaylist("competitive Coding","Introduction");

    // displaying channel data
    c1.channeldata();

    // displaying video data
    c1.videodata();

    // displaying playlists data
    c1.playlistdata();



    // user
    user u1("Mahi");

    // adding subscriptions
    u1.addsubscriptions("Code with Harry");
    u1.addsubscriptions("LUV");
    u1.addsubscriptions("Code Camp");


    // displaying userdata
    u1.userdata();

    //displaying subscriptions
    u1.subscriptionsdata();

    int x;
    cout<<"\nEnter "<<endl;
    cout<<"1-subscribe "<<endl;
    cout<<"2-unsubscribe"<<endl<<endl;
    cin>>x;


    // adding current channel to subscriptions
    u1.subscribeto(c1,x);

    // u1.subscribeto(c1,x);


    // removing current channel from subscriptions
    u1.unsubscribeto(c2,x);

    // checking subscriptionsdata after adding or removing subscriptions
    // u1.subscriptionsdata();

    // c1.channeldata();


    return 0;

}