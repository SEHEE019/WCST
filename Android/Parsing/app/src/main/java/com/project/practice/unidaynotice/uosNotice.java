package com.project.practice.unidaynotice;

import android.app.Activity;
import android.app.ProgressDialog;
import android.os.AsyncTask;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;

public class uosNotice extends Activity {

    private final String htmlUrl = "https://www.uos.ac.kr/korNotice/list.do?list_id=FA1";
    private TextView textView;
    private String htmlContentInStringFormat;
    private ListView listView;
    public ArrayList<String> noticeList = new ArrayList<String>();
    private ArrayAdapter<String> adapter;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_notice);

        listView =(ListView)findViewById(R.id.NoticeView);

        JsoupAsyncTask jsoupAsyncTask = new JsoupAsyncTask();
        jsoupAsyncTask.execute();

        adapter = new ArrayAdapter<String>(this, R.layout.itemstyle, R.id.noticeText,noticeList);

    }

    private class JsoupAsyncTask extends AsyncTask<Void, Void, Void>{
        ProgressDialog progressDialog = new ProgressDialog(
                uosNotice.this
        );
        @Override
        protected void onPreExecute(){
            progressDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
            progressDialog.setMessage("공지사항을 가져오는 중입니다.");
            progressDialog.show();
            super.onPreExecute();
        }
        @Override
        protected Void doInBackground(Void... params) {//네트워크, 병행 일처리
            try {

                URL url = new URL(htmlUrl);
                Document doc = Jsoup.parse(url,3000);

                Element div = doc.select("div[class=cb]").first();
                Elements ul = div.select("ul[class=listType] li[class=on]");
                Elements ite = ul.select("a");

                noticeList.clear();
                for(Element ites : ite){
                    noticeList.add(ites.text()+"\n");
                }

            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        @Override
        protected void onPostExecute(Void result) {
            if(progressDialog != null)
                progressDialog.dismiss();
            listView.setAdapter(adapter);
        }
    }
}
