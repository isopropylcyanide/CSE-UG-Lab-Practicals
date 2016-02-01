package messapp.team.messmunshi;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.sql.Connection;

public class Login extends AppCompatActivity {

    Button btnSignIn;
    EditText etUserName, etPass;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        btnSignIn = (Button) findViewById(R.id.btnSingIn);
        etUserName = (EditText) findViewById(R.id.etUserName);
        etPass = (EditText) findViewById(R.id.etPass);


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_login, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }


        return super.onOptionsItemSelected(item);
    }


    public void authenticateLogin(View view) {
        Intent launchstudent_room;
        launchstudent_room = new Intent(this, student_room.class);
        launchstudent_room.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        launchstudent_room.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK);
        launchstudent_room.addFlags(Intent.FLAG_ACTIVITY_NO_ANIMATION);
        startActivity(launchstudent_room);
    }

}

