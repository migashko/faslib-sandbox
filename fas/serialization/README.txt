Каждый мета элемент:
  tag - сериализатор/десериализатор
  parser_tag - парсер
  target
Каждый мета список
  tag - десериализатор
  target_list
  

? - подумать над названием 
smart<list> (primary_list)
smart_requred<list> (a.k. smart)
sequence<item> - для массивов
item<value>
field<value,value>
value<list> - один десереализатор, остальные проверки- один проход до конца
- ?linear<list> - один проход до конца
- ?linear_requerd<list> - один проход до конца, все элементы обязательны
variant<list> - один из
brute<list> ===? sequence< smart<> >

array< sequence<item> >
object< sequence< field<..., ...> > >