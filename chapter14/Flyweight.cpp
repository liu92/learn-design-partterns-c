class Font {
    private: 
    // unique object key
       string key;
    // object state

public:
   Font(const string& key){
       //....
   }      
};

// 假如 在32位机器上，有10个int字段，一个int 4个byte, 10个字段那么就是40个byte。
// 如果有1024个对象，那么就 1024*40 = 40kb 
// 1字节=8位(1 byte = 8bit)
class FontFactory{
 private: 
   //将字体放在map种，这样就可以共享使用。
    map<string, Font*> fontPool;
 public: 
     Font* GetFont(const string& key){
         // 这个对象出去是最好是只读的，否则这个共享就不成立了，将这个共享给别人了，
          // 如果别人将其修改了 那么其他 地方使用的这个共享，也就被更改了
        map<string, Font*>::iterator item = fontPool.find(key); 
        if(item != footPool.end()){
            //判断这个map中有没有，有就返回，没有将其添加进去。
            return fontPool[key];
        }else
        {
           Font* font = new Font(key);
           fontPool[key] = font;
           return font;
        }
        
     }   
}