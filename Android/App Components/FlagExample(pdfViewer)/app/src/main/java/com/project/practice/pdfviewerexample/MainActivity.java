package com.project.practice.pdfviewerexample;

import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.File;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final EditText editText01 = (EditText)findViewById(R.id.editText01);
        Button button01 = (Button)findViewById(R.id.button01);

        button01.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String filename = editText01.getText().toString();
                if (filename.length()>0){
                    openPDF(filename.trim());
                }else{
                    Toast.makeText(getApplicationContext(),"PDF파일명을 입력하세요.",Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    public void openPDF(String contentsPath){
        File file = new File(contentsPath);

        if (file.exists()){
            Uri path = Uri.fromFile(file);
            Intent intent = new Intent(Intent.ACTION_VIEW);
            intent.setDataAndType(path,"application/pdf");
            intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);

            try{
                startActivity(intent);
            }catch (ActivityNotFoundException e){
                Toast.makeText(getApplicationContext(),"pdf 파일을 위한 뷰어앱을 찾지 못했습니다.",Toast.LENGTH_SHORT).show();
            }
        }else {
            Toast.makeText(getApplicationContext(),"pdf 파일을 찾지 못했습니다.",Toast.LENGTH_SHORT).show();
        }
    }

}
