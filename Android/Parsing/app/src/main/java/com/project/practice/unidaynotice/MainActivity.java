package com.project.practice.unidaynotice;
/*
    * 대학 공지사항 파싱
    * MainActivity에서 스피너로 불러옴
    * 대학별 파싱 주석은 hanyangNotice에 있음
 */

import android.content.Intent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Spinner;
import android.widget.TextView;


public class MainActivity extends ActionBarActivity{

    private int uniNum;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final TextView explanUniPicker = (TextView)findViewById(R.id.explanUniPicker);
        Spinner uniPickSpinner = (Spinner)findViewById(R.id.uniPickSpinner);

        //스피너로 대학 선택
        uniPickSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                switch (i){
                    case 1:
                        Intent intentKyunghee = new Intent(MainActivity.this,kyungheeNotice.class);
                        startActivity(intentKyunghee);
                        break;
                    case 2:
                        Intent intentKorea = new Intent(MainActivity.this, koreaNotice.class);
                        startActivity(intentKorea);
                        break;
                    case 3:
                        Intent intentUos = new Intent(MainActivity.this,uosNotice.class);
                        startActivity(intentUos);
                        break;
                    case 4:
                        Intent intentYonsei = new Intent(MainActivity.this, yonseiNotice.class);
                        startActivity(intentYonsei);
                        break;
                    case 5:
                        Intent intentHufs = new Intent(MainActivity.this,hufsNotice.class);
                        startActivity(intentHufs);
                        break;
                    case 6:
                        Intent intentHanyang = new Intent(MainActivity.this,hanyangNotice.class);
                        startActivity(intentHanyang);
                        break;
                    default:
                        break;
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

    }

}
