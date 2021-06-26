import folium

m = folium.Map(
    location=[36.32150740022885, 127.41184443849869],
    zoom_start=15
)

m.save('map.html')
