#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream ourfile;
	ourfile.open("script.txt");
	ourfile << "pineapple\n";
	ourfile << "list-servers\n";
	ourfile << "list-participants\n";
	ourfile << "login nonexistent@gmail.com FU3QyV\n";

	ourfile << "create-user renzo.zuk@example.com E5wdYaPzv8k7ijA2ioLdSpYb9Xg67t88W8BW8T9BmJm50NZD5Y Renzo\n";
	
	ourfile << "create-user inuyasha@gmail.com WAcd6G 犬夜叉\n";
	ourfile << "create-user sesshomaru@outlook.com NeM8vm 殺生丸\n";
	ourfile << "create-user kagomehigurashi@gmail.com d7RfmA 日暮かごめ\n";
	ourfile << "create-user kykyo@outlook.com W7u2Wv 桔梗\n";

	ourfile << "login inuyasha@gmail.com WAcd6G\n";
	ourfile << "create-server inuyasha-fandom\n";
	ourfile << "list-channels\n";
	ourfile << "create-channel example-1\n";
	ourfile << "create-channel example-1 texto\n";
	ourfile << "enter-channel example-1\n";
	ourfile << "send-message\n";
	ourfile << "send-message oi\n";
	ourfile << "list-messages\n";
	ourfile << "disconnect\n";
	ourfile << "login sesshomaru@outlook.com NeM8vm\n";
	ourfile << "enter-server inuyasha-fandom\n";
	ourfile << "disconnect\n";
	ourfile << "login kagomehigurashi@gmail.com d7RfmA\n";
	ourfile << "enter-server inuyasha-fandom\n";
	ourfile << "disconnect\n";
	ourfile << "login kykyo@outlook.com W7u2Wv\n";
	ourfile << "enter-server inuyasha-fandom\n";
	ourfile << "list-participants\n";
	ourfile << "create-channel example-2 voz\n";
	ourfile << "enter-channel example-2\n";
	ourfile << "list-messages\n";
	ourfile << "send-message olá\n";
	ourfile << "list-messages\n";
	ourfile << "send-message alguém aí?\n";
	ourfile << "list-messages\n";
	ourfile << "leave-channel\n";
	ourfile << "create-channel example-3 texto\n";
	ourfile << "create-channel example-4 voz\n";
	ourfile << "create-channel example-5 texto\n";
	ourfile << "create-channel example-6 voz\n";
	ourfile << "create-channel example-7 texto\n";
	ourfile << "create-channel example-8 voz\n";
	ourfile << "create-channel example-1 texto\n";
	ourfile << "list-channels\n";
	ourfile << "disconnect\n";

	ourfile << "create-user hirohito@outlook.com 84r1Hg Mestre Hirohito\n";
	ourfile << "create-user yoshio.taka@outlook.com 2Hg935 Yoshio Takahashi\n";
	ourfile << "login hirohito@outlook.com 84r1Hg\n";
	ourfile << "create-server hirohito-garden\n";
	ourfile << "create-channel principal texto\n";
	ourfile << "disconnect\n";
	ourfile << "login yoshio.taka@outlook.com 2Hg936\n";
	ourfile << "login yoshio.taka@outlook.com 2Hg935\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Oh, grande mestre, conceda-me a sua sabedoria.\n";
	ourfile << "disconnect\n";
	ourfile << "login hirohito@outlook.com 84r1Hg\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Pois não, meu nobre aprendiz.\n";
	ourfile << "disconnect\n";
	ourfile << "login yoshio.taka@outlook.com 2Hg935\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Oh, grande mestre, eu preciso conquistar a joia de 4 almas.\n";
	ourfile << "disconnect\n";
	ourfile << "login hirohito@outlook.com 84r1Hg\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Para conseguir a joia de 4 almas, você precisa evoluir a sua alma para um nível superior.\n";
	ourfile << "disconnect\n";
	ourfile << "login yoshio.taka@outlook.com 2Hg935\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Como isso seria possível, mestre?\n";
	ourfile << "disconnect\n";
	ourfile << "login hirohito@outlook.com 84r1Hg\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Você deve me conceder uma roda funcional, meu nobre rapaz.\n";
	ourfile << "disconnect\n";
	ourfile << "login yoshio.taka@outlook.com 2Hg935\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Isso parece fácil. Hehe!\n";
	ourfile << "disconnect\n";
	ourfile << "login hirohito@outlook.com 84r1Hg\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Mas não trata-se de qualquer roda, meu jovem.\n";
	ourfile << "send-message Você terá que pegar essa rocha que pesa 40 quilogramas e esculpi-la com uma picareta até que ela se torne uma roda funcional.\n";
	ourfile << "send-message Você terá que provar o seu valor com suor e sangue para ser merecedor da joia de 4 almas.\n";
	ourfile << "list-messages\n";
	ourfile << "disconnect\n";
	ourfile << "login yoshio.taka@outlook.com 2Hg935\n";
	ourfile << "enter-server hirohito-garden\n";
	ourfile << "enter-channel principal\n";
	ourfile << "send-message Droga! Eu estou ferrado, nunca conseguirei conquistar a joia de 4 almas.\n";
	ourfile << "list-messages\n";
	ourfile << "create-channel auxiliar voz\n";
	ourfile << "list-channels\n";
	ourfile << "disconnect\n";

	ourfile << "create-user annajohansson@icloud.com 2rtwK9 Anna Johansson\n"; //half-ok half-ok
	ourfile << "create-user larsandersson@outlook.com QdfU3B Lars Andersson\n"; //ok
	ourfile << "create-user evakarlson@gmail.com c2Ak5a Eva Karlson\n"; //ok
	ourfile << "create-user per.nilsson@outlook.com 8Bkfxd Per Nilsson\n"; //ok
	ourfile << "create-user karlerikson@gmail.com ujDX6K Karl Erikson\n"; //ok
	ourfile << "create-user janlarsson@outlook.com 2FmvDg Jan Larsson\n"; //ok

	ourfile << "create-user arthemisgoddess@hotmail.com 2efPpATCeZsNUVFaLYcb38xGEaV9tSUgmsN9M4PMUYL4zZJps Arthemis the Goddess\n";
	ourfile << "create-user nath@hotmail.com M9XyPwZBkvMEtKMz Nath\n";

	ourfile << "create-user joaomartins@aol.com 1234567890 João Martins Papua Nova Guiné\n";

	ourfile << "create-user jeanmartin@outlook.com pY8VbW Jean Martin\n"; //ok
	ourfile << "create-user mariebernard@gmail.com hRU3rs Marie Bernard\n"; //ok
	ourfile << "create-user michelrobert@yahoo.com 3TuFeB Michel Robert\n"; //ok ok
	ourfile << "create-user clauderichard@icloud.com 92mhCV Claude Richard\n"; //ok ok
	ourfile << "create-user dominiquedurand@gmail.com 43Mjhd Dominique Durand\n"; //ok
	ourfile << "create-user philippedubois@yahoo.com Mrx8g7 Phillipe Dubois\n"; //ok

	ourfile << "create-user antonioblanco@gmail.com TZYs4d Antonio Blanco\n"; //ok
	ourfile << "create-user nellydias33@gmail.com x4PGjq Nelly Dias\n"; //ok
	ourfile << "create-user javier.rivero@outlook.com y9m5KC Javier Rivero\n"; //ok

	ourfile << "login joaomartins@hotmail.com 1234567890\n";
	ourfile << "login joaomartins@hotmail.com 1235467890\n";
	ourfile << "login joaomartins@aol.com 1235467890\n";
	ourfile << "login joaomartins@aol.com 1234567890\n";
	ourfile << "remove-server capybara\n";
	ourfile << "remove-server inuyasha-fandom\n";
	ourfile << "disconnect\n";

	ourfile << "login annajohansson@icloud.com 2rtwK9\n";
	ourfile << "leave-server\n";
	ourfile << "create-server swedish-community\n";
	ourfile << "set-server-invite-code swedish-community sverige\n";
	ourfile << "disconnect\n";
	ourfile << "login jeanmartin@outlook.com pY8VbW\n";
	ourfile << "create-server french-community\n";
	ourfile << "disconnect\n";
	ourfile << "login philippedubois@yahoo.com Mrx8g7\n";
	ourfile << "create-server french-community\n";
	ourfile << "create-server french-community-1\n";
	ourfile << "set-server-invite-code french-community croissant\n";
	ourfile << "set-server-invite-code french-community-1 croissant\n";
	ourfile << "set-server-desc french-community nous aimons des croissant\n";
	ourfile << "set-server-desc french-community-1 nous aimons des croissant\n";
	ourfile << "disconnect\n";
	ourfile << "login antonioblanco@gmail.com TZYs4d\n";
	ourfile << "create-server uruguayan-community\n";
	ourfile << "enter-server swedish-community\n";
	ourfile << "leave-server\n";
	ourfile << "enter-server swedish-community\n";
	ourfile << "disconnect\n";
	ourfile << "login larsandersson@outlook.com QdfU3B\n";
	ourfile << "enter-server swedish-community\n";
	ourfile << "enter-server swedish-community sverige\n";
	ourfile << "disconnect\n";
	ourfile << "login larsandersson@outlook.com QdfU3B\n";
	ourfile << "enter-server swedish-community\n";
	ourfile << "enter-server swedish-community sverige\n";
	ourfile << "list-participants\n";
	ourfile << "disconnect\n";
	ourfile << "login mariebernard@gmail.com hRU3rs\n";
	ourfile << "enter-server french-community\n";
	ourfile << "disconnect\n";
	ourfile << "login nellydias@gmail.com x4PGjq\n";
	ourfile << "login nellydias33@gmail.com x4PGjq\n";
	ourfile << "enter-server uruguayan-community\n";
	ourfile << "disconnect\n";
	ourfile << "login evakarlson@gmail.com c2Ak5a\n";
	ourfile << "enter-server swedish-community sverige\n";
	ourfile << "disconnect\n";
	ourfile << "login dominiquedurand@gmail.com 43Mjhd\n";
	ourfile << "enter-server french-community-1 croissant\n";
	ourfile << "disconnect\n";
	ourfile << "login javier.rivero@outlook.com y9m5KC\n";
	ourfile << "enter-server uruguayan-community\n";
	ourfile << "list-participants\n";
	ourfile << "disconnect\n";
	ourfile << "login per.nilsson@outlook.com 8Bkfxd\n";
	ourfile << "enter-server swedish-community sverige\n";
	ourfile << "disconnect\n";
	ourfile << "login michelrobert@yahoo.com 3TuFeB\n";
	ourfile << "enter-server french-community\n";
	ourfile << "leave-server\n";
	ourfile << "enter-server french-community-1 croissant\n";
	ourfile << "disconnect\n";
	ourfile << "login karlerikson@gmail.com ujDX6K\n";
	ourfile << "enter-server swedish-community sverige\n";
	ourfile << "disconnect\n";
	ourfile << "login clauderichard@icloud.com 92mhCV\n";
	ourfile << "enter-server french-community\n";
	ourfile << "list-participants\n";
	ourfile << "leave-server\n";
	ourfile << "enter-server french-community-1 croissant\n";
	ourfile << "list-participants\n";
	ourfile << "disconnect\n";
	ourfile << "login janlarsson@outlook.com 2FmvDg\n";
	ourfile << "list-servers\n";
	ourfile << "enter-server swedish-community sverige\n";
	ourfile << "disconnect\n";
	ourfile << "login annajohansson@icloud.com 2rtwK9\n";
	ourfile << "enter-server swedish-community\n";
	ourfile << "list-participants\n";
	ourfile << "list-servers\n";
	ourfile << "disconnect\n";
	ourfile << "login philippedubois@yahoo.com Mrx8g7\n";
	ourfile << "list-participants\n";
	ourfile << "set-server-desc french-community-1\n";
	ourfile << "remove-server french-community\n";
	ourfile << "remove-server french-community-1\n";
	ourfile << "list-servers\n";
	ourfile << "disconnect\n";
	ourfile << "quit\n";
	ourfile << "another-test\n";
	ourfile.close();
	return 0;

}
