package com.project.practice.tabexample;

import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;


public class MainActivity extends AppCompatActivity {

    ActionBar actionBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        actionBar = getSupportActionBar();

        actionBar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);

        ActionBar.Tab tab = null;

        tab = actionBar.newTab();
        tab.setText("Analog");
        tab.setTabListener(listener);
        actionBar.addTab(tab);

        tab = actionBar.newTab();
        tab.setText("Digital");
        tab.setTabListener(listener);
        actionBar.addTab(tab);

        tab = actionBar.newTab();
        tab.setText("Calendar");
        tab.setTabListener(listener);
        actionBar.addTab(tab);

    }

    ActionBar.TabListener listener = new ActionBar.TabListener() {
        @Override
        public void onTabSelected(ActionBar.Tab tab, FragmentTransaction ft) {
            int position = tab.getPosition();

            switch (position) {
                case 0:
                    setContentView(R.layout.activity_tab_0);
                    break;
                case 1:
                    setContentView(R.layout.activity_tab_1);
                    break;
                case 2:
                    setContentView(R.layout.activity_tab_2);
                    break;
            }
        }

        @Override
        public void onTabUnselected(ActionBar.Tab tab, FragmentTransaction ft) {

        }

        @Override
        public void onTabReselected(ActionBar.Tab tab, FragmentTransaction ft) {

        }
    };
}
