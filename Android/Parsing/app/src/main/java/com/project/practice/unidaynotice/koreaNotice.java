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

public class koreaNotice extends Activity {

    private final String htmlUrl = "https://www.korea.ac.kr/cop/portalBoard/portalBoardList.do?siteId=university&type=NG&id=university_060201000000";
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
                koreaNotice.this
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


                Element div = doc.select("div[class=datalist_type1 mb20]").first();
                Elements ite = div.select("a[class=sbj]");

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
