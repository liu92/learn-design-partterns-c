class EmployeeDao{

public:
     vector<EmployeeDao> GetEmployees(){
         SqlConnection* connection = new SqlConnection();
         connection->ConnectionString ("...");

         SqlCommand* command = new SqlCommand();
         command->CommandText("...");

         SqlDataReader* reader = command->ExecuteReader();
         while (reader->Read())
         {
             /* code */
         }
         
     }
};


