package com.e.viewholder;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.Date;

public class MainActivity extends AppCompatActivity {
    //listview 객체에 setAdapter를 통해 Adapter 연결
    ListView listView;
    MyListAdapter myListAdapter;
    ArrayList<list_item> list_itemArrayList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //listview를 findViewById를 통해 연결
        listView = (ListView)findViewById(R.id.my_listview);

        //arrayList 객체 생성
        list_itemArrayList = new ArrayList<list_item>();

        //리스트 내용 추가
        list_itemArrayList.add(
                new list_item(R.mipmap.ic_launcher,"보라돌이","최승철")
        );
        list_itemArrayList.add(
                new list_item(R.mipmap.ic_launcher,"뚜비","윤정한")
        );
        list_itemArrayList.add(
                new list_item(R.mipmap.ic_launcher,"나나","우지")
        );
        list_itemArrayList.add(
                new list_item(R.mipmap.ic_launcher,"뽀","부승관")
        );
        list_itemArrayList.add(
                new list_item(R.mipmap.ic_launcher,"햇님","홍지수")
        );

        //adapter 객체 생성, listview 객체에 setAdapter를 통해 Adapter 연결
        myListAdapter = new MyListAdapter(MainActivity.this,list_itemArrayList);
        listView.setAdapter(myListAdapter);
    }
}
