package com.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

public class MyListAdapter extends BaseAdapter {
    Context context;
    ArrayList<list_item> list_itemArrayList;

    TextView title_textview;
    TextView content_textview;
    ImageView profile_imageview;

    public MyListAdapter(Context context, ArrayList<list_item> list_itemArrayList) {
        this.context = context;
        this.list_itemArrayList = list_itemArrayList;
    }

    @Override
    public int getCount() { //이 리스트 뷰가 몇 개의 아이템을 가지고 있는지 알려주는 함수
        //return 0;
        this.list_itemArrayList.size(); // arraylist의 size 만큼 가지고 있음.
    }

    @Override
    public Object getItem(int position) { // 현재 어떤 아이템인지 알려주는 부분
        //return null;
        return this.list_itemArrayList.get(position); //arraylist 객체 중 position 값을 가져올 것이므로.
    }

    @Override
    public long getItemId(int position) { // 현재 어떤 포지션인지 알려주는 부분
        //return 0;
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) { // 리스트뷰에서 아이템과 xml을 연결하여 화면에 표시해주는 부분. 순차적으로 한 칸씩 화면 구성.
        //convertView라는 파라미터를 메소드에서 주는데 이 부분에 item.xml을 불러와야함. 여기는 엑티비티가 아니므로 불러오기위한 약간의 절차가 필요하다. 그 때문에 위에서 Context를 생성자를 통해 받은 것.
        //LayoutInflater.from(context).inflate("레이아웃.xml",null); 하면 View 클래스를 리턴
        //return null;
        if(convertView == null) {
            convertView = LayoutInflater.from(context).inflate(R.layout.item, null);
            // findViewById를 이용하여 위젯의 id를 위젯 객체와 연결해주어야 한다.
            title_textview = (TextView)convertView.findViewById(R.id.title_textview);
            //activity가 아니기 때문에 convertView.findViewById(R.id.xxx) 형식으로 inflate 받은 view를 적어준다.
            content_textview = (TextView)convertView.findViewById(R.id.content_textview);
            profile_imageview = (ImageView)convertView.findViewById(R.id.profile_imageview);
        }
        return convertView;
    }
}
