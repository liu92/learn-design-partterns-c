
//数据库访问基类
class IDBConnection3{

};

class IDBCommand3{

};


class IDataReader3{

};

// 将有相关性的，放在一起
class IDBFactory3{

public:
   //一系列相互依赖的对象 
   virtual IDBConnection3* CreateDBConnection() =0;
   virtual IDBCommand3* CreateDBCommand() =0;
   virtual IDataReader3* CreateDataReader() =0;
};





//支持sqlServer
class SqlConnection3: public IDBConnection3{

}

class SqlCommand3: public IDBCommand3{
    
}

class SqlDataReader3: public IDataReader3{
    
}

//sql链接工厂---继承IDBConnectionFactory
class SqlDBFatory3: public IDBFactory3{
  public: 
   virtual IDBConnection3* CreateDBConnection() =0;

   virtual IDBCommand3* CreateDBCommand() =0;

   virtual IDataReader3* CreateDataReader() =0;
}





//Oracle也是同理
// class OracleConnection: public IDBConnection{

// }

// class OracleCommand: public IDBCommand{
    
// }

// class OracleDataReader: public IDataReader{
    
// }


class EmployeeDao3{
    IDBFactory3* dbFactory;

public:
     vector<EmployeeDao3> GetEmployees(){
         IDBConnection3* connection = 
         dbFactory->CreateDBConnection();
         connetion->ConnectionString("...");

         IDBCommand3* command = dbFactory->CreateDBCommand();
         command->CommandText("...");
         command->SetConnection(connection);//关联性

         IDataReader3* reader = command->ExecuteReader();//关联性
         while (reader->Read())
         {
             /* code */
         }
         
     }
};


