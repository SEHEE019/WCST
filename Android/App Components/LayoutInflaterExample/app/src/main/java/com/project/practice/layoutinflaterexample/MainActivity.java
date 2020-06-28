package com.project.practice.layoutinflaterexample;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.LinearLayout;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button1 = (Button)findViewById(R.id.button1);
        button1.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                viewInflation();
            }
        });
    }
    public void viewInflation(){

        LinearLayout contentLayout = (LinearLayout)findViewById(R.id.contentLayout);
        LayoutInflater inflater = (LayoutInflater)getSystemService(getApplicationContext().LAYOUT_INFLATER_SERVICE);
        inflater.inflate(R.layout.button, contentLayout, true);

        Button selectBtn = (Button)findViewById(R.id.selectBtn);
        final CheckBox alldayCheck = (CheckBox)findViewById(R.id.alldayCheck);
        alldayCheck.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(alldayCheck.isChecked()){
                    alldayCheck.setChecked(false);
                }else{
                    alldayCheck.setChecked(true);
                }
            }
        });
    }
}
