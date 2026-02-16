#include <stdbool.h>
#include <stdlib.h>
#include "../runtime/motion.h"
#include "../sprite_data.h"

double scratch_motion_SpriteX[] = { 0.0, 0.000000, -87.500000, 150.000000, 0.000000, 165.000000, 0.000000, -160.000000, -160.000000, -22.030902, 0.000000, 0.000000, 132.500000, 0.000000, 200.000000, 0.000000, -196.000000, 15.384615, 21.000000, 240.000000, 3.333333, 0.000000, 65.000000 };
double scratch_motion_SpriteY[] = { 0.0, 0.000000, 147.009619, 150.000000, 0.000000, -160.000000, 0.000000, 112.000000, 160.000000, -75.000000, 0.000000, 0.000000, -30.000000, 0.000000, 125.000000, 0.000000, 135.000000, -19.230769, 156.000000, -150.000000, -83.333333, -100.000000, 155.000000 };
double scratch_motion_SpriteDirection[] = { 0.0, 0.000000, -1.047198, 0.000000, 0.000000, 0.000000, 0.000000, -3.141593, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000 };
bool scratch_looks_hidden[] = { false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };
int scratch_motion_SpriteRotStyle[] = { RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround };
int scratch_looks_CostumeIndex[] = { 0, 0, 1, 2, 0, 14, 15, 0, 0, 0, 1, 5, 0, 0, 3, 0, 3, 1, 10, 0, 0, 2, 1 };
int scratch_looks_CostumeCounts[] = { 1, 1, 2, 16, 1, 15, 26, 5, 14, 1, 2, 7, 2, 1, 14, 1, 13, 3, 12, 2, 2, 5, 4 };
char* scratch_looks_CostumeNames[SPRITES][MAX_COSTUME_LENGTH] = {
	{ "backdrop1", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume2", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Win", "Win2", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume1", "costume2", "10", "1", "2", "3", "4", "5", "6", "7", "8", "9", "P1", "P2", "Win", "Win2", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume2", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Asteroids Left", "Level", "Game Over", "Score", "Ship", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Start", "Load Game", "costume1", "Cutscene_2", "Cutscene_3", "Cutscene_4", "Cutscene_5", "Cutscene_6", "Cutscene_7", "Collision", "Good Job! L2", "Good Job! L3", "You Lost 1", "You Lost 2", "Game Over", "Game Won", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	{ "Player_1", "Player_2", "Level_1", "Level_2", "Key", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Renderer", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Lives:", "Win", "Lose", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Cat-a", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Win", "Lose", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Wall", "Wall2", "Player", "Enemy", "costume1", "Win", "Lose", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume1", "costume2", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume1", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "0", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "P1Win", "P2Win", "Tie", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Lose", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Backdrop", "Win", "Win2", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume1", "Win2", "Lose", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume6", "Cube Green", "Cube Blue", "Cube Red", "Cube Yellow", "Empty Left", "Empty RIght", "Cube Purple", "PlaceHolder", "PlaceHolder2", "Claw 1", "Claw 2", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume1", "costume2", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume1", "costume2", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "costume1", "costume2", "costume3", "costume4", "costume5", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "BG Start", "Button Play", "Lose", "Win", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }
 };
char* scratch_looks_CostumeFiles[SPRITES][MAX_COSTUME_LENGTH] = {
	{ "cd21514d0531fdffb22204e0ec5ed84a.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "91795665c23c803a71683d75405e4d3f.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "e328f72104cf1978bf1ed4a9005cea12.svg", "bc3b9e34ee622cd8fa62f2405ae87420.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "c11d3d023bf24e9c615d8e031f20a1dc.svg", "0fb9be3e8397c983338cb71dc84d0b25.svg", "6a6647587458e606a63db79b73305812.svg", "543e4826b7a63c67d2c38e2125f95fda.svg", "31f2b9f4b23cabf4c5e0318873a18694.svg", "651c676cefa557b5dbc3b8f18ab132f7.svg", "6ecef8365fb79f00730e902ba61a60b9.svg", "acd51f5f26f99601c4ace88fb7a84f38.svg", "9d4050b2c93cf5e5b9c59249d1e6678a.svg", "7b19a13be816d0374967d7a6d6799c9d.svg", "77760a7692aafe77de4990f6a6e7580f.svg", "c22f626f9991787c7c36216d595cd602.svg", "c1fdb20b052c621cb15755e47a93b8aa.svg", "e71cc84f53ec25f23ff7255ea96e5392.svg", "09bf1fd1133f9ab65dccbd676e7d771b.svg", "77a5e969791ebc8a300f9280e9bdb970.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "35a3b6dc4bf8da48de127b17149be1c8.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "432e9b46d25126be2bccc3e8b4c86558.svg", "61b380aefc30a3d9f1d3f84bda7b325f.svg", "6ccfa509cc62d6290703c098e66a8d6f.svg", "8a2065972d7c5c7c2760419e2faab293.svg", "e0600dcfcd07feb866e74f102aa0baa9.svg", "674afe9022d5b4987611914ea92a513f.svg", "13d838d55873c479f3548cba6ca04f65.svg", "8f1b32f4ccdbf3ad78ab3e97a6ffd4ee.svg", "d8f8c3137aa3f3a4ccd80d81335f5e1a.svg", "652babfab2f565ba2d1b23b587a6c76b.svg", "268d2588a2d6a337d02f6d594d45f86b.svg", "021d8781bccb56c6a8a1f55d3d6d1bb8.svg", "4c3bc285d0e0c7fd19ba12aa5dad70ea.svg", "acb3b73a8368b5a82f6d595e5872ebe0.svg", "70a34e33dcd5a1fbe1e733d0f6e6a119.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "e3aa776cc6c69cc325e3d24d793eaf9a.svg", "2a5f64181b2d7270a27ef4ad2b5036b3.svg", "14ada5e1bf5dc0fd9ab21f591ba98acc.svg", "a3eb8a0b4b0e681aab8ab8e647e6b9fc.svg", "f82df8d83dbe3bd8b193c742af63bcac.svg", "631f53dc87bc35669aa2e17c2177ea24.svg", "ef35f019abb809ebba02b16257d48198.svg", "2aaa5650840c26b5bec173b252f4d3c2.svg", "2cd8c3f7fcc5107a51617692539af175.svg", "da8a72efb610152d5b7f606f2851d71d.svg", "add0c4374bcdc1631a1ab59283138130.svg", "660f14c938fdf00c0ff572c57c01da62.svg", "e5647f61675b7d208c9c814ec210e72a.svg", "ea0f22fc49d97c52d32fdd4a63f44384.svg", "080ecfa8b630d7bc8eea5b853128f353.svg", "58cfad9614f70954ebfac004973f2b51.svg", "6d3a5890ee25fbc2146601e149c7b98e.svg", "281cfc510950e5f98c18419b5d832e20.svg", "d4ec9a2f77967c913f8c861a506fd057.svg", "43829abe615f2fc68707445c2d19b762.svg", "0b1f4fba477047c3ac1deaae1110b9de.svg", "272a5a7dfd9d823e390bb14022fad322.svg", "88df666632bcae1aec094139a94685ee.svg", "acefdcc631a66cab121c71df3a4f63fd.svg", "461c7fde83b12e55f0822dcbe3ea0b21.svg", "b020bc0a3d5884c21222eaa5a1893722.svg" },
	{ "ed450c4102315600e5a68c580b965423.png", "c8af2a4e7511bb903c07358801052288.png", "757f62d8462f6b1ddf78b84a183f2232.png", "8bcdf48afdecbc78d82af8759e6e1d2f.png", "b407721b3a7b58944559dc583fb38cb6.png", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "3c6241985b581284ec191f9d1deffde8.svg", "432e9b46d25126be2bccc3e8b4c86558.svg", "15b6689dfcb924800033c207a1c51d2f.svg", "6ccfa509cc62d6290703c098e66a8d6f.svg", "da47728d3988e31af80a279dc1c60634.svg", "564b75d6e56571c098b759ba23a55529.svg", "f3b2c82e4fcfca8dcdc818ab57c3e441.svg", "92f4d5f80030c5b491ad3bf33a6bf91e.svg", "c439bbb7be8724619172a8c9ee0d62b7.svg", "e3685d95f2cea6870053489d655e97fd.svg", "47c3c78c2c302954f3acb55895c7f427.svg", "5bb7165b6c73422dfffea0a44c7de898.svg", "e7ce71b91c09f9c3bb0c5a3a25cb3783.svg", "098d4958679bcc754ca252074417c8a0.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "341ff8639e74404142c11ad52929b021.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "319d7e1bc384bc4bf7c1f6e48c64dcdd.svg", "d0d2668493d3f334dc7c5b733c264b27.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "4daf5a71379e491ec6ee8f31e08df827.svg", "b0d837e8b9f4b5acfa890db3d47319bc.svg", "5a8c0dc6aaee60192c85ee41f2b9df4e.svg", "f786240bf930fc0100e889388722f1e7.svg", "cd21514d0531fdffb22204e0ec5ed84a.svg", "739c41c1cfeb6377d2056749cdc2e778.svg", "988d4ced5dbad98067e45313a5262b80.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "bcf454acf82e4504149f7ffe07081dbc.svg", "0fb9be3e8397c983338cb71dc84d0b25.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "684d53c980353d073216e2c5da30cee8.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "5c521e3cc39cb754eed0df903aea1062.svg", "6734e6336150f24b99034d78b45a83ed.svg", "e6b42130543a502c9df4b2b6b78296f2.svg", "7b5c15dc2092b880422490b16813e008.svg", "6f7c2080beb43b5766cc7ec4ea8dcb62.svg", "ca1d493285d87897f43822b3ddeaf5a3.svg", "31f93afa39a58d7a896151313966a242.svg", "8db1435efa8271eaad0e543d07ed8f72.svg", "67e709d089917bf2922092d1bbc2fbce.svg", "ea0ad3366f3aa3292f72f0873072363e.svg", "4c1ffd3200429126e677f22ed8f94889.svg", "fb20db7c5305d88ae94d276287b555df.svg", "f985e283d8d0847911da917a0deb5674.svg", "89edb1c03379ac14318e7c6c032c5ba9.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "c35fa556bf953229daceb9f23ef4ff9c.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "8b3d34582672a95f2b494664efd1d7bf.svg", "523deb1909628d0d32910e44adb2dc7f.svg", "d9838b7a1c77ceebef8ee8884d3a0687.svg", "421aaf19c3ce06e516a5745a7a07f75f.svg", "6f7163a0346ba687db5b7f4e28c11221.svg", "e7609ff2bea6e0b587736aabf59b81a9.svg", "46f09b3fb8c52f2dcc599a731b3a764d.svg", "b103f9f2e16d79bbf7bc4a15daff7ea1.svg", "a9db911fa71ddb9e35b66a08df2d820b.svg", "00baebeb30e6d9e8b50526cb1da50cd8.svg", "ada10248267a7f56b452674b9849b637.svg", "cb3309c96bc9be2890aa944ab72070ae.svg", "8b6ab601254d6bc4e609b454382ad2e3.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "bcf454acf82e4504149f7ffe07081dbc.svg", "8d984fe73bb3b1c6c3f8b7caba855647.svg", "48fd6739b80851d95d089ea8e61ef6e9.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "a75011c78157aa23c795b97287e21eb9.png", "d0f83a03e17bd196cfe7473c117277ec.png", "3e00437b434c02abc9ad7b103dc8dbb3.png", "ac62a50cae42d219c66a7a8fa6b48f3e.png", "8c7735243a4ef746697104e0bec06eb7.png", "edcfcb55db3c9d258c1e569051a0eced.png", "176ce0e9f3602e39794cc7acf91eecda.png", "f320c6380198c0afc0e00782f59d3e3d.png", "d8c311a3bd400ca5ef76beef39c05f06.png", "97e8446398b77a1ff831db25b9a9d43f.png", "71bf1ef469dbb4fe5642f21adf1c1d2f.png", "0103e467038c97dc2fd5413cb1a4be8b.png", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "bcf454acf82e4504149f7ffe07081dbc.svg", "0fb9be3e8397c983338cb71dc84d0b25.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "bcf454acf82e4504149f7ffe07081dbc.svg", "0fb9be3e8397c983338cb71dc84d0b25.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "bcf454acf82e4504149f7ffe07081dbc.svg", "0fb9be3e8397c983338cb71dc84d0b25.svg", "c446646a95cd43c36d25583fdaea3dbc.png", "b508f56f4bf3caf55b6868e0a531eba0.png", "0df3ed826f1f5a42d455ae57abf6dd8d.png", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "51d9f456535a9d90c5b84febe6b3707e.svg", "2b8771f4f52909a8972bf449ea9aa8fb.svg", "759f230e4ff5e93785d8644ae110e851.svg", "1e15c2d5fca296202fe36fbaad68e374.svg", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }
 };
double scratch_looks_RotationCentreX[SPRITES][MAX_COSTUME_LENGTH] = {
	{ 240.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 197.627293, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 42.000000, 52.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 2.300513, 46.000000, 4.500000, 4.500000, 4.500000, 4.500000, 4.500000, 4.500000, 4.500000, 4.500000, 4.500000, 4.500000, 4.500000, 4.500000, 63.250000, 67.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 242.717720, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 68.889938, 27.559971, 59.700000, 29.239967, 10.650000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 27.500000, 272.798995, 105.829964, 265.672825, 265.672825, 265.672825, 265.672825, 265.672825, 265.672825, 265.672815, 136.288100, 136.288100, 119.242633, 119.242633, 152.908600, 136.288100, 5.969997, 5.969997, 5.969997, 5.969997, 5.969997, 5.969997, 5.969997, 5.969997, 5.969997, 5.969997 },
	{ 3.500000, 3.500000, 4.000000, 4.000000, 1.500000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 22.000000, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 26.879974, 88.916665, 88.916665, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 48.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 323.585167, 323.585167, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 15.723795, 15.723795, 9.185750, 9.152870, 0.000000, 338.011389, 338.011389, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 48.000000, 46.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 460.026097, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 5.969994, 11.689987, 342.186272, 342.186272, 342.186272, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 336.336061, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 290.370357, 325.471530, 79.228450, 7.750000, 7.750000, 7.750000, 7.750000, 7.750000, 7.750000, 7.750000, 7.750000, 7.750000, 7.750000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 48.000000, 261.758030, 252.959010, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 4.000000, 7.000000, 7.000000, 7.000000, 7.000000, 2.500000, 7.000000, 7.000000, 7.000000, 7.000000, 6.500000, 8.500000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 48.000000, 46.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 48.000000, 46.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 48.000000, 46.000000, 0.000000, 3.000000, 3.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 256.717700, 62.603740, 267.269707, 267.269707, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
 };
double scratch_looks_RotationCentreY[SPRITES][MAX_COSTUME_LENGTH] = {
	{ 180.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 188.495718, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 19.250000, 19.250000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 2.334999, 53.000000, 19.481250, 19.481250, 19.481250, 19.481250, 19.481250, 19.481250, 19.481250, 19.481250, 19.481250, 19.481250, 19.481250, 19.481250, 19.250000, 19.250000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 182.531501, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 15.367188, 15.598437, 15.367188, 15.367185, 15.367185, 15.367185, 15.367183, 15.367183, 15.367183, 15.367183, 15.367188, 15.367188, 64.467177, 15.367188, 4.935968, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 7.875000, 51.062392, 27.518750, 51.062402, 51.062400, 51.445205, 51.062395, 51.062393, 51.062398, 51.445215, 111.384784, 107.605735, 107.605735, 107.605735, 70.674755, 70.674755, 15.981250, 15.598438, 15.598438, 15.598438, 15.598438, 15.598438, 15.598438, 15.598438, 15.598438, 15.598438 },
	{ 2.000000, 2.000000, 4.000000, 4.000000, 3.500000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 22.000000, 15.367188, 15.598435, 15.367188, 15.598442, 15.598442, 15.598442, 15.598442, 15.598442, 15.598442, 15.598442, 15.367188, 58.199104, 58.198967, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 50.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 210.240865, 210.240855, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 15.904540, 15.904540, 9.097960, 9.097960, 0.000000, 235.203625, 235.203625, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 50.000000, 53.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 209.645016, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 14.884920, 14.884920, 14.884920, 14.884920, 14.884920, 14.884920, 14.884920, 14.884920, 14.884920, 14.884920, 14.884920, 237.038827, 237.038827, 237.038827, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 227.907519, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 190.552275, 188.061985, 53.238217, 18.819875, 18.819880, 18.819875, 18.819880, 18.819875, 18.819880, 18.819875, 18.819880, 18.819875, 18.819880, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 50.000000, 200.498966, 223.682908, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 8.000000, 3.000000, 3.000000, 3.000000, 3.000000, 3.000000, 3.000000, 3.000000, 3.000000, 3.000000, 5.500000, 5.500000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 50.000000, 53.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 50.000000, 53.000000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 50.000000, 53.000000, 0.000000, -0.500000, -0.500000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	{ 190.549520, -4.716561, 205.929681, 205.929681, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
 };
int scratch_sound_SoundEffectCounts[] = { 1, 1, 1, 1, 1, 1, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7 };
char* scratch_sound_SoundEffectNames[SPRITES][MAX_SOUND_LENGTH] = {
	{ "pop", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Coin", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "pop", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", "Wood Tap", "Coin", NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "Meow", "Video Game 2", "Pew", "Crunch", "Oops", "Win", "Lose", NULL }
 };
char* scratch_sound_SoundEffectFiles[SPRITES][MAX_SOUND_LENGTH] = {
	{ "83a9787d4cb6f3b7632b4ddfebf74367.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "88bc8d64867f026ed73daba5aecb1b84.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83a9787d4cb6f3b7632b4ddfebf74367.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", "de5b41c7080396986873d97e9e47acf6.wav", "1f81d88fb419084f4d82ffb859b94ed6.wav", NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL, NULL, NULL, NULL, NULL, NULL, NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", "287c477da485506c5b4ce37c57a64b5f.wav", "21a2cc083ef51767fb13791151194348.wav", "cac3341417949acc66781308a254529c.wav", "1139072c3d2d31fa5903c46632789d08.wav", "db480f6d5ae6d494dbb76ffb9bd995d5.wav", "d73eacaf5a905bf864041c7a70937ac4.wav", NULL }
 };
double scratch_motion_SpriteSize[] = { 100.0, 100.000000, 400.000000, 100.000000, 1.389144, 100.000000, 100.000000, 500.000000, 20.000000, 100.000000, 100.000000, 100.000000, 100.000000, 100.000000, 100.000000, 100.000000, 100.000000, 100.000000, 500.000000, 100.000000, 100.000000, 2000.000000, 100.000000 };
double scratch_motion_SpriteWidth[SPRITES][MAX_COSTUME_LENGTH] = { {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0} };
double scratch_motion_SpriteHeight[SPRITES][MAX_COSTUME_LENGTH] = { {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0} };
double scratch_looks_effects_colour[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_fisheye[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_whirl[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_pixelate[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_mosaic[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_brightness[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_ghost[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
