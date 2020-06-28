package com.project.practice.unidaynotice;

import android.app.Activity;
import android.app.ProgressDialog;
import android.os.AsyncTask;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;

public class hanyangNotice extends Activity {

    private final String htmlUrl = "https://www.hanyang.ac.kr/web/www/main-notices";//대학 공지사항 링크 주소
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
                hanyangNotice.this
        );
        @Override
        protected void onPreExecute(){//연결 전 대기상태
            progressDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
            progressDialog.setMessage("공지사항을 가져오는 중입니다.");
            progressDialog.show();
            super.onPreExecute();
        }
        @Override
        protected Void doInBackground(Void... params) {//네트워크, 공지사항 가져오기
            try {

                URL url = new URL(htmlUrl);
                Document doc = Jsoup.parse(url,3000);

                //공지사항 경로
                Element table = doc.select("table[class=tables-board board-list no-thead bbs-board]").first();
                Elements tbody = table.select("tbody div[class=title-wrap] div[class=title-info] p[class=title]");
                Elements ite = tbody.select("a");

                noticeList.clear();
                for(Element ites : ite){//리스트에 공지사항 추가
                    noticeList.add(ites.text()+"\n");
                }

            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        @Override
        protected void onPostExecute(Void result) {//background Thread가 일을 끝마치고 return 값 넘겨줌
            if(progressDialog != null)
                progressDialog.dismiss();
            listView.setAdapter(adapter);
        }
    }
}
