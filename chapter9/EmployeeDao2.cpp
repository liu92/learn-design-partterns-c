
//数据库访问基类
class IDBConnection{

};

//IDBConnection工厂
class IDBConnectionFactory{
public:
   virtual IDBConnection* CreateDBConnection() =0;
};


class IDBCommand{

};
//IDBCommand的工厂
class IDBCommandFactory{
public:
   virtual IDBCommand* CreateDBCommand() =0;
};




class IDataReader{

};
//IDataReader的工厂
class IDataReaderFactory{
public:
   virtual IDataReader* CreateDataReader() =0;
};





//支持sqlServer
class SqlConnection: public IDBConnection{

}

//sql链接工厂---继承IDBConnectionFactory
class SqlConnectionFatory: public IDBConnectionFactory{
    
}


class SqlCommand: public IDBCommand{
    
}

//SqlCommand工厂---继承IDBCommandFactory
class SqlConnectionFatory: public IDBCommandFactory{

}


class SqlDataReader: public IDataReader{
    
}

//SqlDataReader工厂---继承IDataReaderFactory
class SqlDataReaderFatory: public IDataReaderFactory{

}



//支持Oracle
class OracleConnection: public IDBConnection{

}

class OracleCommand: public IDBCommand{
    
}

class OracleDataReader: public IDataReader{
    
}


class EmployeeDao2{

public:
     vector<EmployeeDao2> GetEmployees(){
         SqlConnection* connection = new SqlConnection();
         connection->ConnectionString = "...";

         SqlCommand* command = new SqlCommand();
         command->CommandText="...";

         SqlDataReader* reader = command->ExecuteReader();
         while (reader->Read())
         {
             /* code */
         }
         
     }
};


