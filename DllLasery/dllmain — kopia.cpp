// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double ThreeComp(double fir, double sec, double bow, double x);
double ThreeComp(double fir, double sec, double bow1, double bow2, double x);
double FourComp(double a, double b, double c, double d, double x, double y);
double Varshni(double Eg_0, double alpha, double beta, double T);
double alc_temperature(double alc_300, double alc_T, double T);
double eps_inplane(double a_epsilon, double a_0);
double eps_outofplane(double C11, double C12, double a_e, double a_0);

double Mat_Blak_0(double hc, double kappa, double a_film, double f, double v);

double hc_MB(double kappa, double a_sub, double a_film, double C11, double C12);
void  martinDin(double* v, double* m,int number, double** envelope_functions, double* energies, double delta_z,int nz);

extern "C" {

	__declspec(dllexport)
	int testDll(int a) {
		return a * 3;
	}
	__declspec(dllexport)
	int calculate(int i1, int i2, int i3, int i4, int i5, int i6,
			double d1, double d2, double d3, double d4, double d5, double d6, double d7, double d8)
	{
		//parametry od uzytkownika

		int material_B = i1, //ktory material B, gdzies nizej jest legenda
			material_C = i2, // ktory material C, gdzies nizej jest legend
			nz = i3,      //liczba pkt do dyskretyzacji. z testow zbieznosci wychodiz, ze 1500 jest spoko
			liczba = i4,     //liczba wartosci wlasnych/funkcji wlasnych liczonych przez Martina Deana
			calka_E_VB = i5,   //uzytkownik wybiera miedzy jakimi pasmami (tutaj z VB a nizej z CB) liczyc calke przekrycia f falowych
			calka_E_CB = i6;

		double sz_B = d1,   //szerokosc struktury B w nm
			sz_C = d2,    //szerokosc struktury C w nm
			sz_A = d3,  //szerokosc podloza A w strukturze A/B/C/A
			T = d4,     //Temperatura 
			x = d5,    //sklad x materialu B
			y = d6,   //no reszta analogicznie
			x2 = d7,     //tylko tutaj dla C
			y2 = d8;


		// int material_B= 0 , //ktory material B, gdzies nizej jest legenda
		// 	material_C= 2 , // ktory material C, gdzies nizej jest legend
		// 	nz = 1500,      //liczba pkt do dyskretyzacji. z testow zbieznosci wychodiz, ze 1500 jest spoko
		// 	liczba = 2,     //liczba wartosci wlasnych/funkcji wlasnych liczonych przez Martina Deana
		// 	calka_E_VB=0,   //uzytkownik wybiera miedzy jakimi pasmami (tutaj z VB a nizej z CB) liczyc calke przekrycia f falowych
		// 	calka_E_CB=0;

		// double sz_B=12.,   //szerokosc struktury B w nm
		// 	   sz_C=6.,    //szerokosc struktury C w nm
		// 	   sz_A=35. ,  //szerokosc podloza A w strukturze A/B/C/A
		// 	   T =300,     //Temperatura 
		// 	   x = 0.9,    //sklad x materialu B
		// 	   y = 0.98,   //no reszta analogicznie
		// 	   x2=0.1,     //tylko tutaj dla C
		// 	   y2=0.3;		   

		double suma = 0.0;  //to trzeba gdzies wyswietlic, bo to wynik calki przekrycia
		double E = 0.0;

		//i jeszcze trzeba wyswietlic grubosci krytyczne tj.
		//pot1[material_B][6] 
		//pot2[material_C][6]


	//to co leci do pliku "wyniki" leci na wykres



		double q = 1.60217733e-19;
		double m0 = 9.1e-31;
		double hb = 1.05459e-34;
		//parametry materialowe GaInAsSb
		double
			Eg_0_GaAs{ 1.519 },
			Eg_0_InAs{ 0.417 },
			Eg_0_GaSb{ 0.812 },
			Eg_0_InSb{ 0.235 },
			Eg_0_AlAs{ 3.099 },
			Eg_0_AlSb{ 2.386 },

			b_Eg_GaInAs{ 0.477 },
			b_Eg_GaInSb{ 0.415 },
			b_Eg_GaAsSb{ 1.43 },
			b_Eg_InAsSb{ 0.67 },
			b_Eg_AlAsSb{ 0.8 },
			b1_Eg_AlGaAs{ -0.127 },
			b2_Eg_AlGaAs{ 1.31 },
			b1_Eg_AlGaSb{ -0.044 },
			b2_Eg_AlGaSb{ 1.22 },



			alpha_GaAs{ 0.0005405 },
			alpha_GaSb{ 0.000417 },
			alpha_InAs{ 0.000276 },
			alpha_InSb{ 0.00032 },
			alpha_AlAs{ 0.000885 },
			alpha_AlSb{ 0.00042 },

			beta_GaAs{ 204 },
			beta_GaSb{ 140 },
			beta_InAs{ 93 },
			beta_InSb{ 170 },
			beta_AlAs{ 530 },
			beta_AlSb{ 140 },


			ac_GaAs{ -7.17 },
			ac_GaSb{ -7.5 },
			ac_InAs{ -5.08 },
			ac_InSb{ -6.94 },
			ac_AlAs{ -5.64 },
			ac_AlSb{ -4.5 },

			av_GaAs{ -1.16 },
			av_GaSb{ -0.8 },
			av_InAs{ -1 },
			av_InSb{ -0.36 },
			av_AlAs{ -2.47 },
			av_AlSb{ -1.4 },

			b_GaAs{ -2.0 },
			b_GaSb{ -2.0 },
			b_InAs{ -1.8 },
			b_InSb{ -2.0 },
			b_AlAs{ -2.3 },
			b_AlSb{ -1.35 },

			SO_GaAs{ 0.341 },
			SO_GaSb{ 0.76 },
			SO_InAs{ 0.39 },
			SO_InSb{ 0.81 },
			SO_AlAs{ 0.28 },
			SO_AlSb{ 0.676 },


			alc_300_GaAs{ 5.65325 },
			alc_300_InAs{ 6.0583 },
			alc_300_GaSb{ 6.0959 },
			alc_300_InSb{ 6.4794 },
			alc_300_AlAs{ 5.6611 },
			alc_300_AlSb{ 6.1355 },
			alc_T_GaAs{ 0.0000388 },
			alc_T_GaSb{ 0.0000472 },
			alc_T_InAs{ 0.0000274 },
			alc_T_InSb{ 0.0000348 },
			alc_T_AlAs{ 0.0000290 },
			alc_T_AlSb{ 0.0000260 },

			b_alc_GaInAs{ 0 },
			b_alc_GaInSb{ 0 },
			b_alc_GaAsSb{ 0 },
			b_alc_InAsSb{ 0 },
			b_alc_AlGaAs{ 0 },
			b_alc_AlGaSb{ 0 },
			b_alc_AlAsSb{ 0 },


			c11_GaAs{ 1221 },
			c11_GaSb{ 884.2 },
			c11_InAs{ 832.9 },
			c11_InSb{ 684.7 },
			c11_AlAs{ 1250 },
			c11_AlSb{ 876.9 },
			c12_GaAs{ 566 },
			c12_GaSb{ 402.6 },
			c12_InAs{ 452.6 },
			c12_InSb{ 373.5 },
			c12_AlAs{ 534 },
			c12_AlSb{ 434.1 },

			VBO_GaAs{ -0.8 },
			VBO_InAs{ -0.59 },
			VBO_GaSb{ -0.03 },
			VBO_InSb{ 0 },
			VBO_AlAs{ -1.33 },
			VBO_AlSb{ -0.41 },

			mhh_GaAs{ 0.55 },
			mhh_GaSb{ 0.37 },
			mhh_InAs{ 0.36 },
			mhh_InSb{ 0.38 },
			mhh_AlAs{ 0.81 },
			mhh_AlSb{ 0.9 },

			mlh_GaAs{ 0.083 },
			mlh_GaSb{ 0.043 },
			mlh_InAs{ 0.026 },
			mlh_InSb{ 0.014 },
			mlh_AlAs{ 0.16 },
			mlh_AlSb{ 0.13 },


			b_VBO_GaInSb{ 0 },
			b_VBO_GaAsSb{ -1.06 },
			b_VBO_InAsSb{ 0 },
			b_VBO_GaInAs{ -0.38 },
			b_VBO_AlGaAs{ 0 },
			b_VBO_AlGaSb{ 0 },
			b_VBO_AlAsSb{ -1.71 },

			b_SO_GaInSb{ 0.1 },
			b_SO_GaAsSb{ 0.6 },
			b_SO_InAsSb{ 1.2 },
			b_SO_GaInAs{ 0.15 },
			b_SO_AlGaAs{ 0 },
			b_SO_AlGaSb{ 0.3 },
			b_SO_AlAsSb{ 0.15 };







		double


			Eg_GaAs{},
			Eg_InAs{},
			Eg_GaSb{},
			Eg_InSb{},
			Eg_AlAs{},
			Eg_AlSb{},


			Eg_GaInAs{},
			Eg_GaInSb{},
			Eg_GaAsSb{},
			Eg_InAsSb{},
			Eg_AlAsSb{},
			Eg_AlGaAs{},
			Eg_AlGaSb{},
			ac_GaInAs{},
			ac_GaInSb{},
			ac_GaAsSb{},
			ac_InAsSb{},
			ac_AlAsSb{},
			ac_AlGaAs{},
			ac_AlGaSb{},
			av_GaInAs{},
			av_GaInSb{},
			av_GaAsSb{},
			av_InAsSb{},
			av_AlAsSb{},
			av_AlGaAs{},
			av_AlGaSb{},
			b_GaInAs{},
			b_GaInSb{},
			b_GaAsSb{},
			b_InAsSb{},
			b_AlAsSb{},
			b_AlGaAs{},
			b_AlGaSb{},


			c11_GaInAs{},
			c11_GaInSb{},
			c11_GaAsSb{},
			c11_InAsSb{},
			c11_AlAsSb{},
			c11_AlGaAs{},
			c11_AlGaSb{},


			mlh_GaInAs{},
			mlh_GaInSb{},
			mlh_GaAsSb{},
			mlh_InAsSb{},
			mlh_AlAsSb{},
			mlh_AlGaAs{},
			mlh_AlGaSb{},

			mhh_GaInAs{},
			mhh_GaInSb{},
			mhh_GaAsSb{},
			mhh_InAsSb{},
			mhh_AlAsSb{},
			mhh_AlGaAs{},
			mhh_AlGaSb{},

			c12_GaInAs{},
			c12_GaInSb{},
			c12_GaAsSb{},
			c12_InAsSb{},
			c12_AlAsSb{},
			c12_AlGaAs{},
			c12_AlGaSb{},

			alc_GaInAs{},
			alc_GaInSb{},
			alc_GaAsSb{},
			alc_InAsSb{},
			alc_AlAsSb{},
			alc_AlGaAs{},
			alc_AlGaSb{},

			SO_GaInAs{},
			SO_GaInSb{},
			SO_GaAsSb{},
			SO_InAsSb{},
			SO_AlAsSb{},
			SO_AlGaAs{},
			SO_AlGaSb{},

			alc_GaAs{},
			alc_InAs{},
			alc_GaSb{},
			alc_InSb{},
			alc_AlAs{},
			alc_AlSb{},


			VBO_GaInAs{},
			VBO_GaInSb{},
			VBO_GaAsSb{},
			VBO_InAsSb{},
			VBO_AlAsSb{},
			VBO_AlGaAs{},
			VBO_AlGaSb{},




			d_Ec_hydro_GaInAsSb{},
			d_Ec_hydro_AlGaAsSb{},
			d_Ev_hydro_GaInAsSb{},
			d_Ev_hydro_AlGaAsSb{},
			d_Ev_biax_GaInAsSb{},
			d_Ev_biax_AlGaAsSb{},
			d_Ev_biax_pl_GaInAsSb{},
			d_Ev_biax_pl_AlGaAsSb{},
			d_Ev_biax_min_GaInAsSb{},
			d_Ev_biax_min_AlGaAsSb{},

			c11_GaInAsSb{},
			c11_AlGaAsSb{},
			c12_GaInAsSb{},
			c12_AlGaAsSb{},

			SO_GaInAsSb{},
			SO_AlGaAsSb{},

			VBO_GaInAsSb{},
			VBO_AlGaAsSb{},
			alc_GaInAsSb{},
			alc_AlGaAsSb{},
			ac_GaInAsSb{},
			ac_AlGaAsSb{},
			av_GaInAsSb{},
			av_AlGaAsSb{},
			b_GaInAsSb{},
			b_AlGaAsSb{},
			Ec_GaInAsSb{},
			Ec_AlGaAsSb{},
			Ev_hh_GaInAsSb{},
			Ev_hh_AlGaAsSb{},
			Ev_lh_GaInAsSb{},
			Ev_lh_AlGaAsSb{},
			Ev_sh_GaInAsSb{},
			Ev_sh_AlGaAsSb{},

			mlh_GaInAsSb{},
			mlh_AlGaAsSb{},
			mhh_GaInAsSb{},
			mhh_AlGaAsSb{},

			d_Ec_hydro_GaInAs{},
			d_Ev_hydro_GaInAs{},
			d_Ev_biax_GaInAs{},
			d_Ev_biax_pl_GaInAs{},
			d_Ev_biax_min_GaInAs{},
			Ec_GaInAs{},
			Ev_hh_GaInAs{},
			Ev_lh_GaInAs{},
			Ev_sh_GaInAs{},

			d_Ec_hydro_GaInSb{},
			d_Ev_hydro_GaInSb{},
			d_Ev_biax_GaInSb{},
			d_Ev_biax_pl_GaInSb{},
			d_Ev_biax_min_GaInSb{},
			Ec_GaInSb{},
			Ev_hh_GaInSb{},
			Ev_lh_GaInSb{},
			Ev_sh_GaInSb{},

			d_Ec_hydro_GaAsSb{},
			d_Ev_hydro_GaAsSb{},
			d_Ev_biax_GaAsSb{},
			d_Ev_biax_pl_GaAsSb{},
			d_Ev_biax_min_GaAsSb{},
			Ec_GaAsSb{},
			Ev_hh_GaAsSb{},
			Ev_lh_GaAsSb{},
			Ev_sh_GaAsSb{},

			d_Ec_hydro_InAsSb{},
			d_Ev_hydro_InAsSb{},
			d_Ev_biax_InAsSb{},
			d_Ev_biax_pl_InAsSb{},
			d_Ev_biax_min_InAsSb{},
			Ec_InAsSb{},
			Ev_hh_InAsSb{},
			Ev_lh_InAsSb{},
			Ev_sh_InAsSb{},

			d_Ec_hydro_AlAsSb{},
			d_Ev_hydro_AlAsSb{},
			d_Ev_biax_AlAsSb{},
			d_Ev_biax_pl_AlAsSb{},
			d_Ev_biax_min_AlAsSb{},
			Ec_AlAsSb{},
			Ev_hh_AlAsSb{},
			Ev_lh_AlAsSb{},
			Ev_sh_AlAsSb{},

			d_Ec_hydro_AlGaSb{},
			d_Ev_hydro_AlGaSb{},
			d_Ev_biax_AlGaSb{},
			d_Ev_biax_pl_AlGaSb{},
			d_Ev_biax_min_AlGaSb{},
			Ec_AlGaSb{},
			Ev_hh_AlGaSb{},
			Ev_lh_AlGaSb{},
			Ev_sh_AlGaSb{},

			d_Ec_hydro_AlGaAs{},
			d_Ev_hydro_AlGaAs{},
			d_Ev_biax_AlGaAs{},
			d_Ev_biax_pl_AlGaAs{},
			d_Ev_biax_min_AlGaAs{},
			Ec_AlGaAs{},
			Ev_hh_AlGaAs{},
			Ev_lh_AlGaAs{},
			Ev_sh_AlGaAs{},


			Eg_GaInAsSb{},
			Eg_AlGaAsSb{};





		double
			hc{};
		//TODO
		double pot1[3][7],
			pot2[3][7];
		//0-GaInAsSb		0-mlh
		//1-AlGaAsSb		1-Ec
		//2-GaInAs			2-Ev_hh
		//3-GaInSb			3-Ev-lh
		//4-GaAsSb			4-Ev_sh
		//5-InAsSb			5-mhh
		//6-AlAsSb			6-grubosc krytyczna
		//7-AlGaAs
		//8-AlGaSb

		for (int y = 0; y < 3; y++)
			for (int u = 0; u < 7; u++)
			{
				pot1[y][u] = 0;
				pot2[y][u] = 0;
			}






		Eg_GaAs = Varshni(Eg_0_GaAs, alpha_GaAs, beta_GaAs, T);
		Eg_InAs = Varshni(Eg_0_InAs, alpha_InAs, beta_InAs, T);
		Eg_GaSb = Varshni(Eg_0_GaSb, alpha_GaSb, beta_GaSb, T);
		Eg_InSb = Varshni(Eg_0_InSb, alpha_InSb, beta_InSb, T);
		Eg_AlAs = Varshni(Eg_0_AlAs, alpha_AlAs, beta_AlAs, T);
		Eg_AlSb = Varshni(Eg_0_AlSb, alpha_AlSb, beta_AlSb, T);

		Eg_GaInAs = ThreeComp(Eg_GaAs, Eg_InAs, b_Eg_GaInAs, x);
		Eg_GaInSb = ThreeComp(Eg_GaSb, Eg_InSb, b_Eg_GaInSb, x);
		Eg_GaAsSb = ThreeComp(Eg_GaAs, Eg_GaSb, b_Eg_GaAsSb, y);
		Eg_InAsSb = ThreeComp(Eg_InSb, Eg_InAs, b_Eg_InAsSb, y);
		Eg_GaInAsSb = FourComp(Eg_GaInAs, Eg_GaInSb, Eg_GaAsSb, Eg_InAsSb, x, y);

		Eg_AlAsSb = ThreeComp(Eg_AlAs, Eg_AlSb, b_Eg_AlAsSb, y);
		Eg_AlGaAs = ThreeComp(Eg_AlAs, Eg_GaAs, b1_Eg_AlGaAs, b2_Eg_AlGaAs, x);
		Eg_AlGaSb = ThreeComp(Eg_AlSb, Eg_GaSb, b1_Eg_AlGaSb, b2_Eg_AlGaSb, x);
		Eg_GaAsSb = ThreeComp(Eg_GaAs, Eg_GaSb, b_Eg_GaAsSb, y);
		Eg_AlGaAsSb = FourComp(Eg_AlGaAs, Eg_AlGaSb, Eg_AlAsSb, Eg_GaAsSb, x, y);

		alc_GaAs = alc_temperature(alc_300_GaAs, alc_T_GaAs, T);
		alc_InAs = alc_temperature(alc_300_InAs, alc_T_InAs, T);
		alc_GaSb = alc_temperature(alc_300_GaSb, alc_T_GaSb, T);
		alc_InSb = alc_temperature(alc_300_InSb, alc_T_InSb, T);
		alc_AlAs = alc_temperature(alc_300_AlAs, alc_T_AlAs, T);
		alc_AlSb = alc_temperature(alc_300_AlSb, alc_T_AlSb, T);

		alc_GaAsSb = ThreeComp(alc_GaAs, alc_GaSb, b_alc_GaAsSb, y);
		alc_GaInAs = ThreeComp(alc_GaAs, alc_InAs, b_alc_GaInAs, x);
		alc_GaInSb = ThreeComp(alc_GaSb, alc_InSb, b_alc_GaInSb, x);
		alc_InAsSb = ThreeComp(alc_InSb, alc_InAs, b_alc_InAsSb, y);
		alc_GaInAsSb = FourComp(alc_GaInAs, alc_GaInSb, alc_GaAsSb, alc_InAsSb, x, y);

		alc_AlAsSb = ThreeComp(alc_AlAs, alc_AlSb, b_alc_AlAsSb, y);
		alc_AlGaAs = ThreeComp(alc_AlAs, alc_GaAs, b_alc_AlGaAs, x);
		alc_AlGaSb = ThreeComp(alc_AlSb, alc_GaSb, b_alc_AlGaSb, x);
		alc_GaAsSb = ThreeComp(alc_GaAs, alc_GaSb, b_alc_GaAsSb, y);
		alc_AlGaAsSb = FourComp(alc_AlGaAs, alc_AlGaSb, alc_AlAsSb, alc_GaAsSb, x, y);

		VBO_GaInAs = ThreeComp(VBO_GaAs, VBO_InAs, b_VBO_GaInAs, x);
		VBO_GaInSb = ThreeComp(VBO_GaSb, VBO_InSb, b_VBO_GaInSb, x);
		VBO_GaAsSb = ThreeComp(VBO_GaAs, VBO_GaSb, b_VBO_GaAsSb, y);
		VBO_InAsSb = ThreeComp(VBO_InAs, VBO_InSb, b_VBO_InAsSb, y);
		VBO_GaInAsSb = FourComp(VBO_GaInAs, VBO_GaInSb, VBO_GaAsSb, VBO_InAsSb, x, y);

		VBO_AlAsSb = ThreeComp(VBO_AlAs, VBO_AlSb, b_VBO_AlAsSb, y);
		VBO_AlGaAs = ThreeComp(VBO_AlAs, VBO_GaAs, b_VBO_AlGaAs, x);
		VBO_AlGaSb = ThreeComp(VBO_AlSb, VBO_GaSb, b_VBO_AlGaSb, x);
		VBO_GaAsSb = ThreeComp(VBO_GaAs, VBO_GaSb, b_VBO_GaAsSb, y);
		VBO_AlGaAsSb = FourComp(VBO_AlGaAs, VBO_AlGaSb, VBO_AlAsSb, VBO_GaAsSb, x, y);

		mlh_GaAsSb = ThreeComp(mlh_GaAs, mlh_GaSb, 0.0, y);
		mlh_GaInAs = ThreeComp(mlh_GaAs, mlh_InAs, 0.0, x);
		mlh_GaInSb = ThreeComp(mlh_GaSb, mlh_InSb, 0.0, x);
		mlh_InAsSb = ThreeComp(mlh_InSb, mlh_InAs, 0.0, y);
		mlh_GaInAsSb = FourComp(mlh_GaInAs, mlh_GaInSb, mlh_GaAsSb, mlh_InAsSb, x, y);

		mlh_AlAsSb = ThreeComp(mlh_AlAs, mlh_AlSb, 0.0, y);
		mlh_AlGaAs = ThreeComp(mlh_AlAs, mlh_GaAs, 0.0, x);
		mlh_AlGaSb = ThreeComp(mlh_AlSb, mlh_GaSb, 0.0, x);
		mlh_GaAsSb = ThreeComp(mlh_GaAs, mlh_GaSb, 0.0, y);
		mlh_AlGaAsSb = FourComp(mlh_AlGaAs, mlh_AlGaSb, mlh_AlAsSb, mlh_GaAsSb, x, y);

		mhh_GaAsSb = ThreeComp(mhh_GaAs, mhh_GaSb, 0.0, y);
		mhh_GaInAs = ThreeComp(mhh_GaAs, mhh_InAs, 0.0, x);
		mhh_GaInSb = ThreeComp(mhh_GaSb, mhh_InSb, 0.0, x);
		mhh_InAsSb = ThreeComp(mhh_InSb, mhh_InAs, 0.0, y);
		mhh_GaInAsSb = FourComp(mhh_GaInAs, mhh_GaInSb, mhh_GaAsSb, mhh_InAsSb, x, y);

		mhh_AlAsSb = ThreeComp(mhh_AlAs, mhh_AlSb, 0.0, y);
		mhh_AlGaAs = ThreeComp(mhh_AlAs, mhh_GaAs, 0.0, x);
		mhh_AlGaSb = ThreeComp(mhh_AlSb, mhh_GaSb, 0.0, x);
		mhh_GaAsSb = ThreeComp(mhh_GaAs, mhh_GaSb, 0.0, y);
		mhh_AlGaAsSb = FourComp(mhh_AlGaAs, mhh_AlGaSb, mhh_AlAsSb, mhh_GaAsSb, x, y);

		c11_GaAsSb = ThreeComp(c11_GaAs, c11_GaSb, 0.0, y);
		c11_GaInAs = ThreeComp(c11_GaAs, c11_InAs, 0.0, x);
		c11_GaInSb = ThreeComp(c11_GaSb, c11_InSb, 0.0, x);
		c11_InAsSb = ThreeComp(c11_InSb, c11_InAs, 0.0, y);
		c11_GaInAsSb = FourComp(c11_GaInAs, c11_GaInSb, c11_GaAsSb, c11_InAsSb, x, y);

		c11_AlAsSb = ThreeComp(c11_AlAs, c11_AlSb, 0.0, y);
		c11_AlGaAs = ThreeComp(c11_AlAs, c11_GaAs, 0.0, x);
		c11_AlGaSb = ThreeComp(c11_AlSb, c11_GaSb, 0.0, x);
		c11_GaAsSb = ThreeComp(c11_GaAs, c11_GaSb, 0.0, y);
		c11_AlGaAsSb = FourComp(c11_AlGaAs, c11_AlGaSb, c11_AlAsSb, c11_GaAsSb, x, y);

		c12_GaAsSb = ThreeComp(c12_GaAs, c12_GaSb, 0.0, y);
		c12_GaInAs = ThreeComp(c12_GaAs, c12_InAs, 0.0, x);
		c12_GaInSb = ThreeComp(c12_GaSb, c12_InSb, 0.0, x);
		c12_InAsSb = ThreeComp(c12_InSb, c12_InAs, 0.0, y);
		c12_GaInAsSb = FourComp(c12_GaInAs, c12_GaInSb, c12_GaAsSb, c12_InAsSb, x, y);

		c12_AlAsSb = ThreeComp(c12_AlAs, c12_AlSb, 0.0, y);
		c12_AlGaAs = ThreeComp(c12_AlAs, c12_GaAs, 0.0, x);
		c12_AlGaSb = ThreeComp(c12_AlSb, c12_GaSb, 0.0, x);
		c12_GaAsSb = ThreeComp(c12_GaAs, c12_GaSb, 0.0, y);
		c12_AlGaAsSb = FourComp(c12_AlGaAs, c12_AlGaSb, c12_AlAsSb, c12_GaAsSb, x, y);

		ac_GaAsSb = ThreeComp(ac_GaAs, ac_GaSb, 0.0, y);
		ac_GaInAs = ThreeComp(ac_GaAs, ac_InAs, 0.0, x);
		ac_GaInSb = ThreeComp(ac_GaSb, ac_InSb, 0.0, x);
		ac_InAsSb = ThreeComp(ac_InSb, ac_InAs, 0.0, y);
		ac_GaInAsSb = FourComp(ac_GaInAs, ac_GaInSb, ac_GaAsSb, ac_InAsSb, x, y);

		ac_AlAsSb = ThreeComp(ac_AlAs, ac_AlSb, 0.0, y);
		ac_AlGaAs = ThreeComp(ac_AlAs, ac_GaAs, 0.0, x);
		ac_AlGaSb = ThreeComp(ac_AlSb, ac_GaSb, 0.0, x);
		ac_GaAsSb = ThreeComp(ac_GaAs, ac_GaSb, 0.0, y);
		ac_AlGaAsSb = FourComp(ac_AlGaAs, ac_AlGaSb, ac_AlAsSb, ac_GaAsSb, x, y);

		av_GaAsSb = ThreeComp(av_GaAs, av_GaSb, 0.0, y);
		av_GaInAs = ThreeComp(av_GaAs, av_InAs, 0.0, x);
		av_GaInSb = ThreeComp(av_GaSb, av_InSb, 0.0, x);
		av_InAsSb = ThreeComp(av_InSb, av_InAs, 0.0, y);
		av_GaInAsSb = FourComp(av_GaInAs, av_GaInSb, av_GaAsSb, av_InAsSb, x, y);

		av_AlAsSb = ThreeComp(av_AlAs, av_AlSb, 0.0, y);
		av_AlGaAs = ThreeComp(av_AlAs, av_GaAs, 0.0, x);
		av_AlGaSb = ThreeComp(av_AlSb, av_GaSb, 0.0, x);
		av_GaAsSb = ThreeComp(av_GaAs, av_GaSb, 0.0, y);
		av_AlGaAsSb = FourComp(av_AlGaAs, av_AlGaSb, av_AlAsSb, av_GaAsSb, x, y);

		b_GaAsSb = ThreeComp(b_GaAs, b_GaSb, 0.0, y);
		b_GaInAs = ThreeComp(b_GaAs, b_InAs, 0.0, x);
		b_GaInSb = ThreeComp(b_GaSb, b_InSb, 0.0, x);
		b_InAsSb = ThreeComp(b_InSb, b_InAs, 0.0, y);
		b_GaInAsSb = FourComp(b_GaInAs, b_GaInSb, b_GaAsSb, b_InAsSb, x, y);

		b_AlAsSb = ThreeComp(b_AlAs, b_AlSb, 0.0, y);
		b_AlGaAs = ThreeComp(b_AlAs, b_GaAs, 0.0, x);
		b_AlGaSb = ThreeComp(b_AlSb, b_GaSb, 0.0, x);
		b_GaAsSb = ThreeComp(b_GaAs, b_GaSb, 0.0, y);
		b_AlGaAsSb = FourComp(b_AlGaAs, b_AlGaSb, b_AlAsSb, b_GaAsSb, x, y);

		SO_GaAsSb = ThreeComp(SO_GaAs, SO_GaSb, b_SO_GaAsSb, y);
		SO_GaInAs = ThreeComp(SO_GaAs, SO_InAs, b_SO_GaInAs, x);
		SO_GaInSb = ThreeComp(SO_GaSb, SO_InSb, b_SO_GaInSb, x);
		SO_InAsSb = ThreeComp(SO_InSb, SO_InAs, b_SO_InAsSb, y);
		SO_GaInAsSb = FourComp(SO_GaInAs, SO_GaInSb, SO_GaAsSb, SO_InAsSb, x, y);

		SO_AlAsSb = ThreeComp(SO_AlAs, SO_AlSb, 0.0, y);
		SO_AlGaAs = ThreeComp(SO_AlAs, SO_GaAs, 0.0, x);
		SO_AlGaSb = ThreeComp(SO_AlSb, SO_GaSb, 0.0, x);
		SO_GaAsSb = ThreeComp(SO_GaAs, SO_GaSb, 0.0, y);
		SO_AlGaAsSb = FourComp(SO_AlGaAs, SO_AlGaSb, SO_AlAsSb, SO_GaAsSb, x, y);



		double alc_podl = alc_GaAs;

		// pot1encjaly dla GaInAsSb

		d_Ec_hydro_GaInAsSb = ac_GaInAsSb * (eps_outofplane(c11_GaInAsSb, c12_GaInAsSb, alc_podl, alc_GaInAsSb) + 2.0 * eps_inplane(alc_podl, alc_GaInAsSb));
		d_Ev_hydro_GaInAsSb = av_GaInAsSb * (eps_outofplane(c11_GaInAsSb, c12_GaInAsSb, alc_podl, alc_GaInAsSb) + 2.0 * eps_inplane(alc_podl, alc_GaInAsSb));
		d_Ev_biax_GaInAsSb = b_GaInAsSb * (eps_outofplane(c11_GaInAsSb, c12_GaInAsSb, alc_podl, alc_GaInAsSb) - eps_inplane(alc_podl, alc_GaInAsSb));
		d_Ev_biax_pl_GaInAsSb = 0.5 * (d_Ev_biax_GaInAsSb - SO_GaInAsSb + sqrt(9.0 * d_Ev_biax_GaInAsSb * d_Ev_biax_GaInAsSb + 2.0 * d_Ev_biax_GaInAsSb * SO_GaInAsSb + SO_GaInAsSb * SO_GaInAsSb));
		d_Ev_biax_min_GaInAsSb = 0.5 * (d_Ev_biax_GaInAsSb - SO_GaInAsSb - sqrt(9.0 * d_Ev_biax_GaInAsSb * d_Ev_biax_GaInAsSb + 2.0 * d_Ev_biax_GaInAsSb * SO_GaInAsSb + SO_GaInAsSb * SO_GaInAsSb));

		pot1[0][5] = mhh_GaInAsSb;
		pot1[0][0] = mlh_GaInAsSb;
		Ec_GaInAsSb = VBO_GaInAsSb + Eg_GaInAsSb + d_Ec_hydro_GaInAsSb;
		pot1[0][1] = Ec_GaInAsSb;
		Ev_hh_GaInAsSb = VBO_GaInAsSb - d_Ev_biax_GaInAsSb + d_Ev_hydro_GaInAsSb;
		pot1[0][2] = Ev_hh_GaInAsSb;
		Ev_lh_GaInAsSb = VBO_GaInAsSb + d_Ev_biax_pl_GaInAsSb + d_Ev_hydro_GaInAsSb;
		pot1[0][3] = Ev_lh_GaInAsSb;
		Ev_sh_GaInAsSb = VBO_GaInAsSb + d_Ev_biax_min_GaInAsSb + d_Ev_hydro_GaInAsSb;
		pot1[0][4] = Ev_sh_GaInAsSb;

		// pot1encjaly dla AlGaAsSb

		d_Ec_hydro_AlGaAsSb = ac_AlGaAsSb * (eps_outofplane(c11_AlGaAsSb, c12_AlGaAsSb, alc_podl, alc_AlGaAsSb) + 2.0 * eps_inplane(alc_podl, alc_AlGaAsSb));
		d_Ev_hydro_AlGaAsSb = av_AlGaAsSb * (eps_outofplane(c11_AlGaAsSb, c12_AlGaAsSb, alc_podl, alc_AlGaAsSb) + 2.0 * eps_inplane(alc_podl, alc_AlGaAsSb));
		d_Ev_biax_AlGaAsSb = b_AlGaAsSb * (eps_outofplane(c11_AlGaAsSb, c12_AlGaAsSb, alc_podl, alc_AlGaAsSb) - eps_inplane(alc_podl, alc_AlGaAsSb));
		d_Ev_biax_pl_AlGaAsSb = 0.5 * (d_Ev_biax_AlGaAsSb - SO_AlGaAsSb + sqrt(9.0 * d_Ev_biax_AlGaAsSb * d_Ev_biax_AlGaAsSb + 2.0 * d_Ev_biax_AlGaAsSb * SO_AlGaAsSb + SO_AlGaAsSb * SO_AlGaAsSb));
		d_Ev_biax_min_AlGaAsSb = 0.5 * (d_Ev_biax_AlGaAsSb - SO_AlGaAsSb - sqrt(9.0 * d_Ev_biax_AlGaAsSb * d_Ev_biax_AlGaAsSb + 2.0 * d_Ev_biax_AlGaAsSb * SO_AlGaAsSb + SO_AlGaAsSb * SO_AlGaAsSb));

		pot1[1][5] = mhh_AlGaAsSb;
		pot1[1][0] = mlh_AlGaAsSb;
		Ec_AlGaAsSb = VBO_AlGaAsSb + Eg_AlGaAsSb + d_Ec_hydro_AlGaAsSb;
		pot1[1][1] = Ec_AlGaAsSb;
		Ev_hh_AlGaAsSb = VBO_AlGaAsSb - d_Ev_biax_AlGaAsSb + d_Ev_hydro_AlGaAsSb;
		pot1[1][2] = Ev_hh_AlGaAsSb;
		Ev_lh_AlGaAsSb = VBO_AlGaAsSb + d_Ev_biax_pl_AlGaAsSb + d_Ev_hydro_AlGaAsSb;
		pot1[1][3] = Ev_lh_AlGaAsSb;
		Ev_sh_AlGaAsSb = VBO_AlGaAsSb + d_Ev_biax_min_AlGaAsSb + d_Ev_hydro_AlGaAsSb;
		pot1[1][4] = Ev_sh_AlGaAsSb;

		pot1[0][6] = hc_MB(2, alc_podl, alc_GaInAsSb, c11_GaInAsSb, c12_GaInAsSb);
		pot1[1][6] = hc_MB(2, alc_podl, alc_AlGaAsSb, c11_AlGaAsSb, c12_AlGaAsSb);

		//druga warstwa XD 




		Eg_GaAs = Varshni(Eg_0_GaAs, alpha_GaAs, beta_GaAs, T);
		Eg_InAs = Varshni(Eg_0_InAs, alpha_InAs, beta_InAs, T);
		Eg_GaSb = Varshni(Eg_0_GaSb, alpha_GaSb, beta_GaSb, T);
		Eg_InSb = Varshni(Eg_0_InSb, alpha_InSb, beta_InSb, T);
		Eg_AlAs = Varshni(Eg_0_AlAs, alpha_AlAs, beta_AlAs, T);
		Eg_AlSb = Varshni(Eg_0_AlSb, alpha_AlSb, beta_AlSb, T);

		Eg_GaInAs = ThreeComp(Eg_GaAs, Eg_InAs, b_Eg_GaInAs, x2);
		Eg_GaInSb = ThreeComp(Eg_GaSb, Eg_InSb, b_Eg_GaInSb, x2);
		Eg_GaAsSb = ThreeComp(Eg_GaAs, Eg_GaSb, b_Eg_GaAsSb, y2);
		Eg_InAsSb = ThreeComp(Eg_InSb, Eg_InAs, b_Eg_InAsSb, y2);
		Eg_GaInAsSb = FourComp(Eg_GaInAs, Eg_GaInSb, Eg_GaAsSb, Eg_InAsSb, x2, y2);

		Eg_AlAsSb = ThreeComp(Eg_AlAs, Eg_AlSb, b_Eg_AlAsSb, y2);
		Eg_AlGaAs = ThreeComp(Eg_AlAs, Eg_GaAs, b1_Eg_AlGaAs, b2_Eg_AlGaAs, x2);
		Eg_AlGaSb = ThreeComp(Eg_AlSb, Eg_GaSb, b1_Eg_AlGaSb, b2_Eg_AlGaSb, x2);
		Eg_GaAsSb = ThreeComp(Eg_GaAs, Eg_GaSb, b_Eg_GaAsSb, y2);
		Eg_AlGaAsSb = FourComp(Eg_AlGaAs, Eg_AlGaSb, Eg_AlAsSb, Eg_GaAsSb, x2, y2);

		alc_GaAs = alc_temperature(alc_300_GaAs, alc_T_GaAs, T);
		alc_InAs = alc_temperature(alc_300_InAs, alc_T_InAs, T);
		alc_GaSb = alc_temperature(alc_300_GaSb, alc_T_GaSb, T);
		alc_InSb = alc_temperature(alc_300_InSb, alc_T_InSb, T);
		alc_AlAs = alc_temperature(alc_300_AlAs, alc_T_AlAs, T);
		alc_AlSb = alc_temperature(alc_300_AlSb, alc_T_AlSb, T);

		alc_GaAsSb = ThreeComp(alc_GaAs, alc_GaSb, b_alc_GaAsSb, y2);
		alc_GaInAs = ThreeComp(alc_GaAs, alc_InAs, b_alc_GaInAs, x2);
		alc_GaInSb = ThreeComp(alc_GaSb, alc_InSb, b_alc_GaInSb, x2);
		alc_InAsSb = ThreeComp(alc_InSb, alc_InAs, b_alc_InAsSb, y2);
		alc_GaInAsSb = FourComp(alc_GaInAs, alc_GaInSb, alc_GaAsSb, alc_InAsSb, x2, y2);

		alc_AlAsSb = ThreeComp(alc_AlAs, alc_AlSb, b_alc_AlAsSb, y2);
		alc_AlGaAs = ThreeComp(alc_AlAs, alc_GaAs, b_alc_AlGaAs, x2);
		alc_AlGaSb = ThreeComp(alc_AlSb, alc_GaSb, b_alc_AlGaSb, x2);
		alc_GaAsSb = ThreeComp(alc_GaAs, alc_GaSb, b_alc_GaAsSb, y2);
		alc_AlGaAsSb = FourComp(alc_AlGaAs, alc_AlGaSb, alc_AlAsSb, alc_GaAsSb, x2, y2);

		VBO_GaInAs = ThreeComp(VBO_GaAs, VBO_InAs, b_VBO_GaInAs, x2);
		VBO_GaInSb = ThreeComp(VBO_GaSb, VBO_InSb, b_VBO_GaInSb, x2);
		VBO_GaAsSb = ThreeComp(VBO_GaAs, VBO_GaSb, b_VBO_GaAsSb, y2);
		VBO_InAsSb = ThreeComp(VBO_InAs, VBO_InSb, b_VBO_InAsSb, y2);
		VBO_GaInAsSb = FourComp(VBO_GaInAs, VBO_GaInSb, VBO_GaAsSb, VBO_InAsSb, x2, y2);

		VBO_AlAsSb = ThreeComp(VBO_AlAs, VBO_AlSb, b_VBO_AlAsSb, y2);
		VBO_AlGaAs = ThreeComp(VBO_AlAs, VBO_GaAs, b_VBO_AlGaAs, x2);
		VBO_AlGaSb = ThreeComp(VBO_AlSb, VBO_GaSb, b_VBO_AlGaSb, x2);
		VBO_GaAsSb = ThreeComp(VBO_GaAs, VBO_GaSb, b_VBO_GaAsSb, y2);
		VBO_AlGaAsSb = FourComp(VBO_AlGaAs, VBO_AlGaSb, VBO_AlAsSb, VBO_GaAsSb, x2, y2);

		mlh_GaAsSb = ThreeComp(mlh_GaAs, mlh_GaSb, 0.0, y2);
		mlh_GaInAs = ThreeComp(mlh_GaAs, mlh_InAs, 0.0, x2);
		mlh_GaInSb = ThreeComp(mlh_GaSb, mlh_InSb, 0.0, x2);
		mlh_InAsSb = ThreeComp(mlh_InSb, mlh_InAs, 0.0, y2);
		mlh_GaInAsSb = FourComp(mlh_GaInAs, mlh_GaInSb, mlh_GaAsSb, mlh_InAsSb, x2, y2);

		mlh_AlAsSb = ThreeComp(mlh_AlAs, mlh_AlSb, 0.0, y2);
		mlh_AlGaAs = ThreeComp(mlh_AlAs, mlh_GaAs, 0.0, x2);
		mlh_AlGaSb = ThreeComp(mlh_AlSb, mlh_GaSb, 0.0, x2);
		mlh_GaAsSb = ThreeComp(mlh_GaAs, mlh_GaSb, 0.0, y2);
		mlh_AlGaAsSb = FourComp(mlh_AlGaAs, mlh_AlGaSb, mlh_AlAsSb, mlh_GaAsSb, x2, y2);

		mhh_GaAsSb = ThreeComp(mhh_GaAs, mhh_GaSb, 0.0, y2);
		mhh_GaInAs = ThreeComp(mhh_GaAs, mhh_InAs, 0.0, x2);
		mhh_GaInSb = ThreeComp(mhh_GaSb, mhh_InSb, 0.0, x2);
		mhh_InAsSb = ThreeComp(mhh_InSb, mhh_InAs, 0.0, y2);
		mhh_GaInAsSb = FourComp(mhh_GaInAs, mhh_GaInSb, mhh_GaAsSb, mhh_InAsSb, x2, y2);

		mhh_AlAsSb = ThreeComp(mhh_AlAs, mhh_AlSb, 0.0, y2);
		mhh_AlGaAs = ThreeComp(mhh_AlAs, mhh_GaAs, 0.0, x2);
		mhh_AlGaSb = ThreeComp(mhh_AlSb, mhh_GaSb, 0.0, x2);
		mhh_GaAsSb = ThreeComp(mhh_GaAs, mhh_GaSb, 0.0, y2);
		mhh_AlGaAsSb = FourComp(mhh_AlGaAs, mhh_AlGaSb, mhh_AlAsSb, mhh_GaAsSb, x2, y2);

		c11_GaAsSb = ThreeComp(c11_GaAs, c11_GaSb, 0.0, y2);
		c11_GaInAs = ThreeComp(c11_GaAs, c11_InAs, 0.0, x2);
		c11_GaInSb = ThreeComp(c11_GaSb, c11_InSb, 0.0, x2);
		c11_InAsSb = ThreeComp(c11_InSb, c11_InAs, 0.0, y2);
		c11_GaInAsSb = FourComp(c11_GaInAs, c11_GaInSb, c11_GaAsSb, c11_InAsSb, x2, y2);

		c11_AlAsSb = ThreeComp(c11_AlAs, c11_AlSb, 0.0, y2);
		c11_AlGaAs = ThreeComp(c11_AlAs, c11_GaAs, 0.0, x2);
		c11_AlGaSb = ThreeComp(c11_AlSb, c11_GaSb, 0.0, x2);
		c11_GaAsSb = ThreeComp(c11_GaAs, c11_GaSb, 0.0, y2);
		c11_AlGaAsSb = FourComp(c11_AlGaAs, c11_AlGaSb, c11_AlAsSb, c11_GaAsSb, x2, y2);

		c12_GaAsSb = ThreeComp(c12_GaAs, c12_GaSb, 0.0, y2);
		c12_GaInAs = ThreeComp(c12_GaAs, c12_InAs, 0.0, x2);
		c12_GaInSb = ThreeComp(c12_GaSb, c12_InSb, 0.0, x2);
		c12_InAsSb = ThreeComp(c12_InSb, c12_InAs, 0.0, y2);
		c12_GaInAsSb = FourComp(c12_GaInAs, c12_GaInSb, c12_GaAsSb, c12_InAsSb, x2, y2);

		c12_AlAsSb = ThreeComp(c12_AlAs, c12_AlSb, 0.0, y2);
		c12_AlGaAs = ThreeComp(c12_AlAs, c12_GaAs, 0.0, x2);
		c12_AlGaSb = ThreeComp(c12_AlSb, c12_GaSb, 0.0, x2);
		c12_GaAsSb = ThreeComp(c12_GaAs, c12_GaSb, 0.0, y2);
		c12_AlGaAsSb = FourComp(c12_AlGaAs, c12_AlGaSb, c12_AlAsSb, c12_GaAsSb, x2, y2);

		ac_GaAsSb = ThreeComp(ac_GaAs, ac_GaSb, 0.0, y2);
		ac_GaInAs = ThreeComp(ac_GaAs, ac_InAs, 0.0, x2);
		ac_GaInSb = ThreeComp(ac_GaSb, ac_InSb, 0.0, x2);
		ac_InAsSb = ThreeComp(ac_InSb, ac_InAs, 0.0, y2);
		ac_GaInAsSb = FourComp(ac_GaInAs, ac_GaInSb, ac_GaAsSb, ac_InAsSb, x2, y2);

		ac_AlAsSb = ThreeComp(ac_AlAs, ac_AlSb, 0.0, y2);
		ac_AlGaAs = ThreeComp(ac_AlAs, ac_GaAs, 0.0, x2);
		ac_AlGaSb = ThreeComp(ac_AlSb, ac_GaSb, 0.0, x2);
		ac_GaAsSb = ThreeComp(ac_GaAs, ac_GaSb, 0.0, y2);
		ac_AlGaAsSb = FourComp(ac_AlGaAs, ac_AlGaSb, ac_AlAsSb, ac_GaAsSb, x2, y2);

		av_GaAsSb = ThreeComp(av_GaAs, av_GaSb, 0.0, y2);
		av_GaInAs = ThreeComp(av_GaAs, av_InAs, 0.0, x2);
		av_GaInSb = ThreeComp(av_GaSb, av_InSb, 0.0, x2);
		av_InAsSb = ThreeComp(av_InSb, av_InAs, 0.0, y2);
		av_GaInAsSb = FourComp(av_GaInAs, av_GaInSb, av_GaAsSb, av_InAsSb, x2, y2);

		av_AlAsSb = ThreeComp(av_AlAs, av_AlSb, 0.0, y2);
		av_AlGaAs = ThreeComp(av_AlAs, av_GaAs, 0.0, x2);
		av_AlGaSb = ThreeComp(av_AlSb, av_GaSb, 0.0, x2);
		av_GaAsSb = ThreeComp(av_GaAs, av_GaSb, 0.0, y2);
		av_AlGaAsSb = FourComp(av_AlGaAs, av_AlGaSb, av_AlAsSb, av_GaAsSb, x2, y2);

		b_GaAsSb = ThreeComp(b_GaAs, b_GaSb, 0.0, y2);
		b_GaInAs = ThreeComp(b_GaAs, b_InAs, 0.0, x2);
		b_GaInSb = ThreeComp(b_GaSb, b_InSb, 0.0, x2);
		b_InAsSb = ThreeComp(b_InSb, b_InAs, 0.0, y2);
		b_GaInAsSb = FourComp(b_GaInAs, b_GaInSb, b_GaAsSb, b_InAsSb, x2, y2);

		b_AlAsSb = ThreeComp(b_AlAs, b_AlSb, 0.0, y2);
		b_AlGaAs = ThreeComp(b_AlAs, b_GaAs, 0.0, x2);
		b_AlGaSb = ThreeComp(b_AlSb, b_GaSb, 0.0, x2);
		b_GaAsSb = ThreeComp(b_GaAs, b_GaSb, 0.0, y2);
		b_AlGaAsSb = FourComp(b_AlGaAs, b_AlGaSb, b_AlAsSb, b_GaAsSb, x2, y2);

		SO_GaAsSb = ThreeComp(SO_GaAs, SO_GaSb, b_SO_GaAsSb, y2);
		SO_GaInAs = ThreeComp(SO_GaAs, SO_InAs, b_SO_GaInAs, x2);
		SO_GaInSb = ThreeComp(SO_GaSb, SO_InSb, b_SO_GaInSb, x2);
		SO_InAsSb = ThreeComp(SO_InSb, SO_InAs, b_SO_InAsSb, y2);
		SO_GaInAsSb = FourComp(SO_GaInAs, SO_GaInSb, SO_GaAsSb, SO_InAsSb, x2, y2);

		SO_AlAsSb = ThreeComp(SO_AlAs, SO_AlSb, 0.0, y2);
		SO_AlGaAs = ThreeComp(SO_AlAs, SO_GaAs, 0.0, x2);
		SO_AlGaSb = ThreeComp(SO_AlSb, SO_GaSb, 0.0, x2);
		SO_GaAsSb = ThreeComp(SO_GaAs, SO_GaSb, 0.0, y2);
		SO_AlGaAsSb = FourComp(SO_AlGaAs, SO_AlGaSb, SO_AlAsSb, SO_GaAsSb, x2, y2);



		// pot1encjaly dla GaInAsSb

		d_Ec_hydro_GaInAsSb = ac_GaInAsSb * (eps_outofplane(c11_GaInAsSb, c12_GaInAsSb, alc_podl, alc_GaInAsSb) + 2.0 * eps_inplane(alc_podl, alc_GaInAsSb));
		d_Ev_hydro_GaInAsSb = av_GaInAsSb * (eps_outofplane(c11_GaInAsSb, c12_GaInAsSb, alc_podl, alc_GaInAsSb) + 2.0 * eps_inplane(alc_podl, alc_GaInAsSb));
		d_Ev_biax_GaInAsSb = b_GaInAsSb * (eps_outofplane(c11_GaInAsSb, c12_GaInAsSb, alc_podl, alc_GaInAsSb) - eps_inplane(alc_podl, alc_GaInAsSb));
		d_Ev_biax_pl_GaInAsSb = 0.5 * (d_Ev_biax_GaInAsSb - SO_GaInAsSb + sqrt(9.0 * d_Ev_biax_GaInAsSb * d_Ev_biax_GaInAsSb + 2.0 * d_Ev_biax_GaInAsSb * SO_GaInAsSb + SO_GaInAsSb * SO_GaInAsSb));
		d_Ev_biax_min_GaInAsSb = 0.5 * (d_Ev_biax_GaInAsSb - SO_GaInAsSb - sqrt(9.0 * d_Ev_biax_GaInAsSb * d_Ev_biax_GaInAsSb + 2.0 * d_Ev_biax_GaInAsSb * SO_GaInAsSb + SO_GaInAsSb * SO_GaInAsSb));

		pot2[0][5] = mhh_GaInAsSb;
		pot2[0][0] = mlh_GaInAsSb;
		Ec_GaInAsSb = VBO_GaInAsSb + Eg_GaInAsSb + d_Ec_hydro_GaInAsSb;
		pot2[0][1] = Ec_GaInAsSb;
		Ev_hh_GaInAsSb = VBO_GaInAsSb - d_Ev_biax_GaInAsSb + d_Ev_hydro_GaInAsSb;
		pot2[0][2] = Ev_hh_GaInAsSb;
		Ev_lh_GaInAsSb = VBO_GaInAsSb + d_Ev_biax_pl_GaInAsSb + d_Ev_hydro_GaInAsSb;
		pot2[0][3] = Ev_lh_GaInAsSb;
		Ev_sh_GaInAsSb = VBO_GaInAsSb + d_Ev_biax_min_GaInAsSb + d_Ev_hydro_GaInAsSb;
		pot2[0][4] = Ev_sh_GaInAsSb;

		// pot2encjaly dla AlGaAsSb

		d_Ec_hydro_AlGaAsSb = ac_AlGaAsSb * (eps_outofplane(c11_AlGaAsSb, c12_AlGaAsSb, alc_podl, alc_AlGaAsSb) + 2.0 * eps_inplane(alc_podl, alc_AlGaAsSb));
		d_Ev_hydro_AlGaAsSb = av_AlGaAsSb * (eps_outofplane(c11_AlGaAsSb, c12_AlGaAsSb, alc_podl, alc_AlGaAsSb) + 2.0 * eps_inplane(alc_podl, alc_AlGaAsSb));
		d_Ev_biax_AlGaAsSb = b_AlGaAsSb * (eps_outofplane(c11_AlGaAsSb, c12_AlGaAsSb, alc_podl, alc_AlGaAsSb) - eps_inplane(alc_podl, alc_AlGaAsSb));
		d_Ev_biax_pl_AlGaAsSb = 0.5 * (d_Ev_biax_AlGaAsSb - SO_AlGaAsSb + sqrt(9.0 * d_Ev_biax_AlGaAsSb * d_Ev_biax_AlGaAsSb + 2.0 * d_Ev_biax_AlGaAsSb * SO_AlGaAsSb + SO_AlGaAsSb * SO_AlGaAsSb));
		d_Ev_biax_min_AlGaAsSb = 0.5 * (d_Ev_biax_AlGaAsSb - SO_AlGaAsSb - sqrt(9.0 * d_Ev_biax_AlGaAsSb * d_Ev_biax_AlGaAsSb + 2.0 * d_Ev_biax_AlGaAsSb * SO_AlGaAsSb + SO_AlGaAsSb * SO_AlGaAsSb));

		pot2[1][5] = mhh_AlGaAsSb;
		pot2[1][0] = mlh_AlGaAsSb;
		Ec_AlGaAsSb = VBO_AlGaAsSb + Eg_AlGaAsSb + d_Ec_hydro_AlGaAsSb;
		pot2[1][1] = Ec_AlGaAsSb;
		Ev_hh_AlGaAsSb = VBO_AlGaAsSb - d_Ev_biax_AlGaAsSb + d_Ev_hydro_AlGaAsSb;
		pot2[1][2] = Ev_hh_AlGaAsSb;
		Ev_lh_AlGaAsSb = VBO_AlGaAsSb + d_Ev_biax_pl_AlGaAsSb + d_Ev_hydro_AlGaAsSb;
		pot2[1][3] = Ev_lh_AlGaAsSb;
		Ev_sh_AlGaAsSb = VBO_AlGaAsSb + d_Ev_biax_min_AlGaAsSb + d_Ev_hydro_AlGaAsSb;
		pot2[1][4] = Ev_sh_AlGaAsSb;

		pot2[0][6] = hc_MB(2, alc_podl, alc_GaInAsSb, c11_GaInAsSb, c12_GaInAsSb);
		pot2[1][6] = hc_MB(2, alc_podl, alc_AlGaAsSb, c11_AlGaAsSb, c12_AlGaAsSb);

		double** funkcje;// 2 wymiarowa tablica przechowujaca funkcje wlasne
		double* energie;// tablica przechowujaca obliczone energie
		double* energie2;// tablica przechowujaca obliczone energie
		double** funkcje2;// 2 wymiarowa tablica przechowujaca funkcje wlasne

		energie = new double[liczba];
		energie2 = new double[liczba];
		funkcje = new double* [nz]; //alokacja pamieci
		for (int i = 0; i < nz; ++i)
			funkcje[i] = new double[liczba]; //alokacja pamieci
		funkcje2 = new double* [nz]; //alokacja pamieci
		for (int i = 0; i < nz; ++i)
			funkcje2[i] = new double[liczba]; //alokacja pamieci

		double* v1;
		double* v2;
		double* m;
		m = new double[nz];
		v1 = new double[nz];
		v2 = new double[nz];
		//VALENCE BAND
		for (int b = 0; b < nz; b++)
		{
			x = (2 * sz_A + sz_B + sz_C) * (float)b / nz;

			if (x > 0 && x <= sz_A)
			{
				m[b] = 0.083 * m0; y = 0.8;
			}

			if (x > sz_A && x <= sz_A + sz_B)
			{

				if (pot1[material_B][2] > pot1[material_B][3])
				{
					m[b] = pot1[material_B][5] * m0;
					y = -pot1[material_B][2];
				}



				if (pot1[material_B][2] <= pot1[material_B][3])
				{
					m[b] = pot1[material_B][0] * m0;
					y = -pot1[material_B][3];
				}
			}
			if (x > sz_A + sz_B && x <= sz_A + sz_B + sz_C)
			{
				if (pot2[material_C][2] > pot2[material_C][3])
				{
					m[b] = pot2[material_C][5] * m0;
					y = -pot2[material_C][2];
				}



				if (pot2[material_C][2] <= pot2[material_C][3])
				{
					m[b] = pot2[material_C][0] * m0;
					y = -pot2[material_C][3];
				}


			}
			if (x > sz_A + sz_B + sz_C && x <= sz_A + sz_B + sz_C + sz_A)
			{
				m[b] = 0.083 * m0; y = 0.8;
			}

			v1[b] = y * q;
		}
		double dz;
		dz = (sz_A + sz_B + sz_C + sz_A) / (float)nz;
		dz = dz * 1e-9;//przeliczenie na m

		martinDin(v1, m, liczba, funkcje, energie, dz, nz);

		//CONDUCTION BAND
		for (int a = 0; a < nz; a++)
		{
			x = (2 * sz_A + sz_B + sz_C) * (float)a / nz;

			if (x > 0 && x <= sz_A)
			{
				m[a] = 1. * m0; y = 0.622482;
			}

			if (x > sz_A && x <= sz_A + sz_B)
			{
				m[a] = 1. * m0;
				y = pot1[material_B][1];
			}
			if (x > sz_A + sz_B && x <= sz_A + sz_B + sz_C)
			{
				m[a] = 1. * m0;
				y = pot2[material_C][1];
			}
			if (x > sz_A + sz_B + sz_C && x <= sz_A + sz_B + sz_C + sz_A)
			{
				m[a] = 1. * m0; y = 0.622482;
			}

			v2[a] = y * q;

		}

		martinDin(v2, m, liczba, funkcje2, energie2, dz, nz);

		fstream plik;
		plik.open("wynik.dat", ios::out);


		for (int s = 1; s < nz; s++)
		{
			plik << s << "\t" << -v1[s] / q << "\t" << v2[s] / q << "\t";

			for (int iter = 0; iter<int(liczba); iter++)
				plik << -energie[iter] / q << "\t";

			for (int iter = 0; iter < liczba; iter++)
				plik << energie2[iter] / q << "\t";

			for (int iter = 0; iter < liczba; iter++)
				plik << funkcje[s][iter] - energie[iter] / q << "\t";
			for (int iter = 0; iter < liczba; iter++)
				plik << funkcje2[s][iter] + energie2[iter] / q << "\t";

			plik << endl;


		}


		/*double z = 0.;


		for (int i = 0; i < nz; i++)
		{
			z = z + dz;
			suma = suma + funkcje[i][calka_E_VB] * funkcje2[i][calka_E_CB];
		}
		E = -energie[calka_E_VB] / q + energie2[calka_E_CB] / q;
		cout << E << endl;
		cout << suma;*/
		return 0;
	}
}

double Mat_Blak_0(double hc, double kappa, double a_film, double f, double v)
{
	return a_film / sqrt(2.0) / kappa / 3.141592653589793 / f * (1.0 - 0.25 * v) / (1. + v) * (log(hc * sqrt(2.0) / a_film) + 1.0) - hc;
}
double hc_MB(double kappa, double a_sub, double a_film, double C11, double C12)
{
	double
		test1{}, test2{},
		hc{},
		f{},
		v{};

	f = abs((a_sub - a_film) / a_film);
	v = C12 / (C12 + C11);

	hc = 2;
	test1 = Mat_Blak_0(hc, kappa, a_film, f, v);
	for (hc = 3; hc < 1000000; hc++)
	{
		test2 = Mat_Blak_0(hc, kappa, a_film, f, v);
		if (test1 * test2 <= 0)
			break;
	}
	return hc / 10.0; //nm

}
double ThreeComp(double fir, double sec, double bow, double x)
{
	return fir * x + sec * (1 - x) - x * (1 - x) * bow;
}
double ThreeComp(double fir, double sec, double bow1, double bow2, double x)
{
	return fir * x + sec * (1 - x) - x * (1 - x) * (bow1 + bow2 * x);
}
double FourComp(double P_wx, double P_yz, double P_wy, double P_xz, double x, double y)
{
	return (x * (1 - x) * (y * P_wx + (1 - y) * P_yz) + y * (1 - y) * (x * P_wy + (1 - x) * P_xz)) / (x * (1 - x) + y * (1 - y));
}
double Varshni(double Eg_0, double alpha, double beta, double T)
{
	return (Eg_0 - alpha * T * T / (T + beta));
}
double alc_temperature(double alc_300, double alc_T, double T)
{
	return (alc_300 + (alc_T * (T - 300)));
}
double eps_inplane(double a_epsilon, double a_0)
{
	return ((a_epsilon - a_0) / a_0);
}
double eps_outofplane(double C11, double C12, double a_e, double a_0)
{
	return ((-2.0) * ((a_e - a_0) / a_0) * (C12 / C11));
}
void  martinDin(double* v, double* m,const int number, double** envelope_functions, double* energies, double delta_z,int _nz)
{
	double q = 1.0e-19;
	double m0 = 9.1e-31;
	double hb = 1.05459e-34;
	const int nz = _nz;
	int i, km, n, nu, i0, k, ii;
	//double d[nz][2];
	double** d = new double* [nz];
	for (int i = 0; i < nz; ++i)
		d[i] = new double[2];
	//double enn[number];
	double* enn = new double[number];
	double x, x0, x1, xk, dx, xroot, xw, y1, y2, dok, w1, w2, delta, xmx, xmy, g0;
	//double del_m[nz], del_p[nz], psi_dwsz[nz], energia, calka;
	double* del_m = new double[nz];
	double* del_p = new double[nz];
	double* psi_dwsz = new double[nz];
	double* pr = new double[nz];
	double potmin, potmax, max_psi,energia,calka;

	g0 = 2.0 * m0 / hb / hb * (1.0e-3 * q) * 1.0e-20;

	max_psi = 100.0;
	dok = 1.0e-24;
	delta = delta_z / 1.0e-10;


	potmin = v[0];
	potmax = v[0];
	k = nz / 2;

	for (i = 0; i < nz; i++)
	{
		if (v[i] < potmin)
		{
			potmin = v[i];
			k = i;
		}
		if (v[i] > potmax)
		{
			potmax = v[i];
		}
	}

	potmin = (potmin)*delta * delta * g0 / q * 1.0e3;
	potmax = (potmax)*delta * delta * g0 / q * 1.0e3;

	xmx = potmin;
	xmy = potmax;
	x0 = xmx;
	x1 = xmy;
	km = nz - 1;



	for (i = 0; i < nz - 1; i++)
	{
		w1 = 1.0 / m[i] * m0;
		w2 = 1.0 / m[i + 1] * m0;
		d[i][1] = w1 + w2;
		d[i][1] = d[i][1] + delta * delta * g0 * v[i] / q * 1.0e3;
		d[i + 1][0] = -w2;
	}

	d[nz - 1][1] = d[nz - 2][1];
	d[nz - 1][0] = d[nz - 2][0];




	for (i = 1; i < number + 1; i++)
	{

		nu = 1;
	l7401:
		xk = 0.0;
		nu = nu + 1;
		if (nu > 100) { goto l7513; }
		xw = (float)i;
		dx = x1 - x0;
		if (dx < dok) { goto l7513; }
		x = (x0 + x1) / 2.0;
		y1 = d[0][1] - x;
		if (y1 > 0.0) { goto l7133; }
		xk = xk + 1.0;
		if (xk >= xw) { goto l7403; }
	l7133:

		for (n = 1; n < km; n++)
		{
			y2 = d[n][1] - x - d[n][0] * d[n][0] / y1;
			if (y2 > 0.0) { goto l7200; }
			xk = xk + 1.0;
			if (xk >= xw) { goto l7403; }
		l7200:
			y1 = y2;
		}


		y2 = d[nz - 1][1] - x - d[nz - 1][0] * d[nz - 1][0] / y1;
		if (y2 > 0.0) { goto l7202; }
		xk = xk + 1.0;
		if (xk > xw) { goto l7403; }
	l7202:
		dx = x1 - x0;
		if (dx < dok) { goto l7513; }
		x0 = x;
		goto l7401;
	l7403:
		dx = x1 - x0;
		if (dx < dok) { goto l7513; }
		x1 = x;
		goto l7401;
	l7513:

		xroot = 0.50 * (x + x0);
		pr[i - 1] = xroot;
		enn[i - 1] = xroot / delta / delta / g0;


		energies[i - 1] = enn[i - 1] * q * 1.0e-3;


		x1 = xmy;
		x0 = xroot;
	}



	for (ii = 0; ii < number; ii++)
	{

		energia = enn[ii] * delta * delta * g0;
		max_psi = 1.0;

		for (i = 0; i < nz; i++)
		{
			psi_dwsz[i] = 0.0;
		}


	l1000:
		i0 = k;
		psi_dwsz[i0] = 10.0;
		del_m[0] = 1.0 / (d[0][1] - energia);
		del_p[nz - 1] = 1.0 / (d[nz - 1][1] - energia);
		for (i = 1; i < nz; i++)
		{
			del_m[i] = 1.0 / (d[i][1] - energia - d[i][0] * d[i][0] * del_m[i - 1]);
		}

		for (i = 1; i < nz - 1; i++)
		{

			del_p[nz - i - 1] = 1.0 / (d[nz - i - 1][1] - energia - d[nz - i][0] * d[nz - i][0] *
				del_p[nz - i]);

		}
		for (i = i0; i < nz - 1; i++)
		{
			psi_dwsz[i + 1] = -d[i + 1][0] * del_p[i + 1] * psi_dwsz[i];

			if (psi_dwsz[i + 1] > max_psi)
			{
				max_psi = psi_dwsz[i - 1];
				k = i + 1;
			}

		}


		for (i = i0; i >= 1; i--)
		{
			psi_dwsz[i - 1] = -d[i][0] * del_m[i - 1] * psi_dwsz[i];

		}

		if (i0 != k) { goto l1000; }


		calka = 0.0e0;
		for (i = 0; i < nz; i++)
		{
			calka = calka + psi_dwsz[i] * psi_dwsz[i];

		}

		for (i = 0; i < nz; i++)
		{
			psi_dwsz[i] = psi_dwsz[i] / sqrt(calka);
			envelope_functions[i][ii] = psi_dwsz[i];
		}
	}
	return;
}





		// plik2 << suma<< endl; //calka przekrycia
		// plik2 << E << endl; //energia przrejcia
		// plik2 << 1240. / E << endl; //dlugosc fali 
		// plik2 << pot1[material_B][6] << endl;  //grubosc krytyczna1
		// plik2 << pot2[material_C][6] << endl;  //grubosc kryczyna 2