# Gömülü Sistem Nedir ?
Herhangi bir sistem içerisinde yer alarak, o sistemi akıllı hale getiren elektronik yazılım ve donanım ile oluşmuş entegre(birbirinden farklı birimlerin birbiri ile bağlantılı olma durumu) sisteme **gömülü sistem** denir. 

Gömülü sistemin içerisindeki yazılımların bilgisayarımızdaki yazılımlardan farkı, tek bir görevi yerine getirmesi ve kullanıcı ile dolaylı olarak etkileşimde bulunmasıdır. 

Günlük hayatımızda kullandığımız hemen hemen her eşyada bu sistemler kullanılmaktadır.

Gömülü sistemlerin genellikle bir işletim sistemleri yoktur ya da özelleştirilmiş gömülü işletim sistemleri kullanılmaktadır.

# Mikrodenetleyici ve Mikroişlemci Nedir ?

## Mikroişlemci:
Yapısında CPU, ön bellek ve I/O portları bulunan ve aynı anda birçok işlemi yapabilen bir elektronik bileşendir.

## Mikrodenetleyici:
Yapısında mikroişlemcileri, seri ve paralel portları, sayıcıları, kesiciler, zamanlayıcılar, çeviriciler ve bellek gibi birimleri bulunduran mikro bilgisayarlardır.

# Gerçek Zamanlı İşletim Sistemleri (Real-Time Operating System — RTOS)

Her işletim sistemi, bir ihtiyacı karşılamak için geliştirilmiştir. Android, mobil cihazları akıllı hale getirmek; Windows, kişisel bilgisayarların her ihtiyaçlarını karşılamak için geliştirilmiştir. Ancak işletim sistemleri yalnızca günlük kullanıcıların ihtiyaçları için kullanılmaz. Kritik düzeydeki süreçleri yönetmek için de kullanılır. Çünkü sistemdeki en ufak gecikme kritik problemlere yol açabilir (savunma sanayisi, uzay teknolojileri vs.). Gerçek zamanlı işletim sistemleri tam da bu sorunu çözmeye yarar.

Günlük hayatta kullandığımız işletim sistemlerinde bir process eğer gereğinden fazla uzun sürerse veya bir deadlock (donanımı işgal eden sonsuz döngü) ‘a sebep olursa, veya herhangi bir sebepten dolayı bir interrupt (sistem kesme çağrısı) oluşursa bu, sistemin iş planlama akış şemasında kararsızlığa yol açabilir. Bu da sistemin donmasına, belleğin boşaltılması veya tamamen dolmasına, işlemlerin geciktirmesine ve hatta sistemin çökmesine sebep olabilmektedir.

## RTOS ve GPOS 

### GPOS (General Purpose Operating System)
Windows, Android gibi standart kullanım amacına sahip işletim sistemlerinin genel adıdır. GPOS işletim sistemleri, Task Schedule adında bir yapıya sahiptir. Bu yapı vasıtası ile yürütülmekte olan bir programın anlık işlevleri olan process leri çeşitli algoritmalara göre bir sıra ile işleme sokarlar. Sistem tarafından bir interrupt (kesme) çağrısı gelene kadar process işlemcide çalıştırılmaya devam eder. İşlemin tamamlanmasının ardından işlemciye sıradaki process girer.

### RTOS 
Gerçek zamanlı işletim sistemleri ise çekirdeğinde iş planlama akış şemasında ufak bir fark ile tasarlanırlar. Standart işletim sistemlerinde giren bir process; işi bitene, I/0 çağrısı bekleyene veya sistem tarafından sonlandırılana kadar işlemcide kalmaya devam etmektedir. Ancak RTOS larda bir işlem koşturulurken daha öncelikli (priority) işlem başlatıldığı anda o esnada işlem gören process çıkarılır ve bekleme moduna geçirilir. Bir diğer (ve asıl) fark ise zamanlama konusundadır.

RTOS’lar zamanda sapmaya toleranslarına göre üç ana sınıfa ayrılırlar.

- **Hard Real Time :** Bu tür RTOS sistemlerinde zamanda sapmalara tolerans son derece azdır. Zamanında tamamlanmayan görevler sistem için tehlike arz edebilir. Hard Real Time RTOS sistemler genelde RTOS mantığına uygun dizayn edilmiş paralel işlemcili mimariler üzerinde çalıştırılırlar ancak bu zorunlu değildir.

- **Soft Real Time :** Bu tür RTOS sistemler RTOS ile GPOS arasında kalmış ara bir türe benzetilebilir. Sapmalar tolare edilebilir ve çok da önemli değildir.

- **Firm Real Time :** Bu tür RTOS sistemler ya hep ya hiç mantığına benzetilebilir. Zamanında zamamlanmayan görev ne olursa olsun kaldırılır. Bu eğer bir mikrokernel işlevi ise sistemin çökmesi beklenir. Ancak safemode modu aktif ise diğer processler ram’de iken kernel baştan başlatılabilir.

### Gerçek Zamanlı İşletim Sistemi Özellikleri
- **Görev Önceliği (Task Priority):** En çok ihtiyaç duyulan görevi tanımlama ve kaynağı elde etmek için denetimi gerçekleştirme.

- **Görevler Arası İletişim Mekanizması (Task Communication Mechanism):** Birden fazla görevin iletişim kurması ve veri bütünlüğünü sağlaması için senkronizasyon mekanizması gerekir.

- **Çoklu Görev (Multitasking):** Birden fazla görevin aynı anda yürütmeye olanak sağlar.

- **Belirleyici Davranış (Deterministic behaviour):** Süreçler ve kesintiler (interrupts) belirli bir süre içinde ele alınır.

- **Tanımlanmış Yığın Kullanımı (Defined stack usage):** Her görev için tanımlanmış bir yığın alanı tahsis edilir.
 
- **Sistem Yönetimi (System management):** Kaynak yönetimi yerine, uygulama geliştirmeye olanak tanır.

### Gerçek Zamanlı İşletim Sistemleri Neden Tercih Edilir

- Önceliğe dayalı programlama sunar
- Daha az hafıza kullanımı
- Az kaynak tüketimi
- Hızlı yanıt süreleri
- API servisi sağlarlar
- Zaman kaybı olmaksızın süreçlere odaklanır
- Modüler geliştirmeye teşvik eder
- Görev tabanlı tasarımı vardır

# Kesmeler (Interrupts)
Kesme anlamına gelen Interrupt, birden fazla işlemin yapıldığı projelerde sıklıkla kullanılan bir özelliktir. Interrupt, Arduino'nun çalışması sırasında veya dışarıdan bir etkiyle meydana gelen olaylara otomatik olarak tepki vermesidir. Interrupt sayesinde Arduino sürekli beklenen olayın gerçekleşip gerçekleşmemesini beklemez. Arduino, başka görevleri yerine getirirken bu olay gerçekleştiğinde, otomatik olarak bu olaydan haberdar olur.

Diyelim ki Arduino'nun Interrupt özelliği bulunan bir düğmesine basıldığında bilgisayara veri yollamak istiyoruz. Bunu kolay bir şekilde loop fonksiyonunun içine yazacağımız kodlar ile yapabiliriz. Fakat Arduino'nun bu projedeki tek görevi bu olmayabilir. Arduino başka işlemler yaparken kullanıcı düğmeye basabilir. Böyle bir durumda Arduino düğmeye basıldığını anlayamayacaktır.

Böyle bir hatanın önüne geçilmesi için Interrupt kullanılmalıdır. Düğmeye atanacak bir Interrupt, Arduino başka bir işlem yapmakta olsa bile, düğmeye basıldığı gibi Arduino'ya haber verecektir. Arduino düğmeye basıldığında yapılması gereken işlemleri yaptıktan sonra, kaldığı yerden diğer işlemlere otomatik olarak geri dönecektir.

Arduino'da farklı görevlerde kullanılmak üzere çeşitli Interrupt'lar (kesmeler) bulunur. Zaman kesmesi (timer interrupt) ve dış kesmeler (external İnterrupt) en yaygın olarak kullanılan Arduino kesmeleridir.

- **Zaman Kesmeleri:** Zaman kesmesi (timer interrupt), belirli süre aralıklarında belirli görevlerin yapılabilmesi için kullanılır. Örneğin bir LED'in saniyede bir yakıp söndürülmesi gerekmektedir. Bu işlem için loop fonksiyonunun kullanılması yerine, zaman kesmesinin kullanılması Arduino programının rahatlamasını sağlayacaktır. Kullanılan kesme her saniyede bir Arduino'ya haber vererek, LED'in yakılıp söndürülmesini sağlayacaktır.

- **Dış Kesmeleri:** Arduino projelerinde sıkça kullanılan diğer bir kesme çeşidi de dış kesmelerdir. Dış kesmeler, Arduino'nun özel pinlerinde gerçekleşen voltaj değişimlerini takip eden kesmelerdir. Örneğin Arduino'nun dış kesme pinine bağlanmış bir düğmeye basıldığında, dış kesme Arduino'ya otomatik olarak haber verir. Bu kesme sayesinde Arduino sürekli olarak düğmeye basılıp basılmadığını kontrol etmek zorunda kalmaz, bu sırada başka işlemleri yerine getirebilir.

# Veri İletimi

İki elektronik cihazın birbirleri arasında iletişimi sağlamak için verileri düzenlemeye yarayan, standart olarak kabul edilmiş kurallar dizisi olan iletişim protokolleri ile sistemler iletişim sağlarlar. Veri iletimi 2 farklı gruba ayrılır. 

## Paralel Haberleşme 

Paralel İletişim, paralel kanallar üzerinden bir seferde çoklu veri bitlerinin gönderilmesi/alınması işlemidir. Paralel iletişimde alıcı taraf verinin uzunluğunu, başlangıç/bitiş bitlerini ve iletim hızını bilmek zorunda değildir. Hızlı ve basittir ancak fazla kullandığımızdan dolayı maliyeti arttırır.
Seri iletişime göre gürültü dayanıklılığı çok daha azdır.

## Seri Haberleşme 

Seri iletişimde bir seferde bir bit veri akışı olur. Saat hattının olup olmamasına göre iki şekilde gerçekleşir.

- **Full-Dublex Seri İletişim:** Bu yöntemde her iki taraf da alıcı ve verici olarak çalışır. Yani aynı anda veri gönderip alabilirler. Telefon konuşmaları gibi.

- **Half-Dublex Seri İletişim:** Bu yöntemde de her iki taraf alıcı ve verici olarak çalışabilir. Fakat biri veri gönderirken diğer dinlemek zorundadır. Aynı anda karşı taraf veri yollayamaz .Telsiz konuşmaları gibi.

- **Simplex Seri İletişim:** Bu yöntemde bir taraf verici bir taraf alıcıdır. Değişmesi mümkün değildir. Radyo yayınları gibi.

### Senkron Haberleşme
Senkron haberleşme gerçekleştirilirken, gönderilen veri biti ve alınan veri biti birbiriyle uyum içerisinde olmalıdır. İletişimi gerçekleştirecek olan aygıtlar eş zamanlı olarak çalışmak zorundadır. Yani alıcı ve verici aynı saat (clock) üzerinde olmalıdır. 

### Asenkron Haberleşme
Asenkron haberleşme yapmak için belirli bir clock’a ihtiyaç duyulmaz. Veri herhangi bir anda iletilebilir. Belirli standartlar kullanılarak gerçekleştirilir ve Senkron haberleşmeye göre daha yavaş bir iletim olur.

## Haberleşme Protokolleri
Haberleşme protokolleri UART, USART, SPI ve I2C protokolleridir. 

- **UART Haberleşmesi (Universal Asynchronous Receiver Transmitter):** Adından da anlaşılacağı üzere **Asenkron bir haberleşme** gerçekleştiren bir yapıdır. Aslında bir protokol değildir, bir çiptir. Ama bu çip programlanabilir olduğu için belirli prokollere sahiptir.

- **SPI Protokolü (Serial Peripheral Interface):** ***Senkron haberleşme protokollerinden*** bir tanesidir.  Fully duplex (eş zamanlı çift yönlü çalışabilen) olarak çalışabilir. Senkron olarak çalıştığı için mutlaka bir clock sinyaline ihtiyaç duyulur. Kısa mesafeli iletimde kullanılır.

- **I2C Protokolü (Inter-Integrated Circuit):** ***Senkron haberleşme protokollerinden*** diğer bir tanesidir. Half-duplex (yarı eş zamanlı çift yönlü çalışabilen) olarak çalışır. Yani veri iletimi çift yönlü olur ancak aynı anda hem veri gönderilip hem de alınamaz. Buna telsizleri örnek verebiliriz. Minimum bilgi alışverişi gerçektirilecek yerlerde tercih edilir.