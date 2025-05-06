#using <System.dll>
#using <System.Data.dll>
#include <iostream>
#include <pch.h>


using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

int main(array<System::String^>^ args)
{
    // Cambia la cadena de conexi�n seg�n tu configuraci�n
    String^ cadenaConexion = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Escuela;Integrated Security=True;";

    // Crear la conexi�n a la base de datos
    SqlConnection^ conexion = gcnew SqlConnection(cadenaConexion);

    try
    {
        // Abrir la conexi�n
        conexion->Open();
        Console::WriteLine("Conexi�n exitosa a la base de datos.");

        // Realizar una consulta SQL
        String^ consulta = "SELECT * FROM Estudiantes";
        SqlCommand^ comando = gcnew SqlCommand(consulta, conexion);
        SqlDataReader^ lector = comando->ExecuteReader();

        // Mostrar los resultados de la consulta
        while (lector->Read())
        {
            Console::WriteLine("ID: {0}, Nombre: {1}, Edad: {2}",
                lector["Id"], lector["Nombre"], lector["Edad"]);
        }

        // Cerrar la conexi�n
        conexion->Close();
    }
    catch (Exception^ ex)
    {
        // Manejar errores de conexi�n
        Console::WriteLine("Error: {0}", ex->Message);
    }

    // Esperar que el usuario presione una tecla antes de finalizar
    Console::ReadLine();
    return 0;
}
