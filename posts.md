---
layout: page
title: "Posts"
permalink: /posts/
main_nav: true
---


{% assign categories_max = 0 %}
{% for category in site.categories %}
  {% if category[1].size > categories_max %}
    {% assign categories_max = category[1].size %}
  {% endif %}
{% endfor %}

<ul class="taxonomy__index">
  {% for i in (1..categories_max) reversed %}
    {% for category in site.categories %}
      {% if category[1].size == i %}
        <li>
          <a href="#{{ category[0] | slugify }}">
            <strong>{{ category[0] }}</strong> <span class="taxonomy__count">{{ i }}</span>
          </a>
        </li>
      {% endif %}
    {% endfor %}
  {% endfor %}
</ul>

{% for i in (1..categories_max) reversed %}
  {% for category in site.categories %}
  {% if category[1].size == i %}
    {% capture cat %}{{ category | first }}{% endcapture %}
  <section id="{{ category[0] | slugify | downcase }}" class="taxonomy__section">
    <h2 class="archive__subtitle">{{ category[0] }}</h2>  {% for desc in site.descriptions %}
    {% if desc.cat == cat %}
      <p class="desc"><em>{{ desc.desc }}</em></p>
    {% endif %}
  {% endfor %}
  <ul class="posts-list">
  {% for post in site.categories[cat] %}
    <li>
      <strong>
        <a href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a>
      </strong>
      <span class="post-date">- {{ post.date | date_to_long_string }}</span>
      {% for tag in post.tags %} 
      <!-- <span class="pre-tag" style=" color:green; font-weitght:bold; background:white; font-style:italic">[{{tag}}]</span> -->
      <button type="button" onclick="location.href='{{ site.baseurl }}/tag/{{ tag }}'" title="{{ tag[0] }}" rel="{{ tag[1].size }}" style="font-size: 0.9em">{{ tag }}</button>
      {% endfor %}
    </li>
  {% endfor %}
  </ul>
  {% if forloop.last == false %}<hr>{% endif %}
  {% endif %}
  {% endfor %}
{% endfor %}
<br>
