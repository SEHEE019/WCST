package com.listview;

public class list_item {
    private int profile_image;
    private String title;
    private String content;

    public list_item(int profile_image, String title, String content) {
        this.profile_image = profile_image;
        this.title = title;
        this.content = content;
    }

    public int getProfile_image() {
        return profile_image;
    }

    public void setProfile_image(int profile_image) {
        this.profile_image = profile_image;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
