import folium
# 새로운 지도 객체 생성
map_osm1 = folium.Map(location=[36.5252, 52.7855], zoom_start='값')

# 마커 객체 생성
marker1 = folium.Marker([36.5252, 52.7855],
                        popup='서울특별시청')  # 팝업 이름)

marker1.add_to(map_osm1)  # 마커 객체를 지도에 추가함
map_osm1