void SRB1_DRmin2_SR_SRB_original_N_1()
{
//=========Macro generated from canvas: Canvas1/Canvas1
//=========  (Mon Jun  4 22:01:34 2018) by ROOT version 6.12/06
   TCanvas *Canvas1 = new TCanvas("Canvas1", "Canvas1",0,22,900,756);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   Canvas1->SetHighLightColor(2);
   Canvas1->Range(0,0,1,1);
   Canvas1->SetFillColor(0);
   Canvas1->SetBorderMode(0);
   Canvas1->SetBorderSize(2);
   Canvas1->SetLogy();
   Canvas1->SetTickx(1);
   Canvas1->SetTicky(1);
   Canvas1->SetLeftMargin(0.16);
   Canvas1->SetRightMargin(0.05);
   Canvas1->SetTopMargin(0.05);
   Canvas1->SetBottomMargin(0.16);
   Canvas1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0.3,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-1.21509,-2.30103,6.379847,3.493865);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetLogy();
   pad1->SetTickx(1);
   pad1->SetTicky(1);
   pad1->SetLeftMargin(0.16);
   pad1->SetRightMargin(0.05);
   pad1->SetTopMargin(0.05);
   pad1->SetBottomMargin(0);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   TH1D *SMBkgPlot__1 = new TH1D("SMBkgPlot__1","Title",6,0.0001,6.0001);
   SMBkgPlot__1->SetBinContent(1,1.75365);
   SMBkgPlot__1->SetBinContent(2,2.433873);
   SMBkgPlot__1->SetBinContent(3,1.852218);
   SMBkgPlot__1->SetBinContent(4,0.5294913);
   SMBkgPlot__1->SetBinError(1,0.9405259);
   SMBkgPlot__1->SetBinError(2,0.8714829);
   SMBkgPlot__1->SetBinError(3,0.7889607);
   SMBkgPlot__1->SetBinError(4,0.3094605);
   SMBkgPlot__1->SetMinimum(0.005);
   SMBkgPlot__1->SetMaximum(1600);
   SMBkgPlot__1->SetEntries(148);
   SMBkgPlot__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#999999");
   SMBkgPlot__1->SetFillColor(ci);
   SMBkgPlot__1->SetFillStyle(3004);
   SMBkgPlot__1->SetLineWidth(7);

   ci = TColor::GetColor("#ff0000");
   SMBkgPlot__1->SetMarkerColor(ci);
   SMBkgPlot__1->SetMarkerStyle(20);
   SMBkgPlot__1->SetMarkerSize(0.001);
   SMBkgPlot__1->GetXaxis()->SetTitle("SRB1_DRmin2");
   SMBkgPlot__1->GetXaxis()->SetRange(1,6);
   SMBkgPlot__1->GetXaxis()->SetLabelFont(42);
   SMBkgPlot__1->GetXaxis()->SetLabelSize(0.05);
   SMBkgPlot__1->GetXaxis()->SetTitleSize(0.05);
   SMBkgPlot__1->GetXaxis()->SetTitleOffset(1.4);
   SMBkgPlot__1->GetXaxis()->SetTitleFont(42);
   SMBkgPlot__1->GetYaxis()->SetTitle("Events");
   SMBkgPlot__1->GetYaxis()->SetLabelFont(42);
   SMBkgPlot__1->GetYaxis()->SetLabelSize(0.045);
   SMBkgPlot__1->GetYaxis()->SetTitleSize(0.045);
   SMBkgPlot__1->GetYaxis()->SetTitleOffset(1.5);
   SMBkgPlot__1->GetYaxis()->SetTitleFont(42);
   SMBkgPlot__1->GetZaxis()->SetLabelFont(42);
   SMBkgPlot__1->GetZaxis()->SetLabelSize(0.05);
   SMBkgPlot__1->GetZaxis()->SetTitleSize(0.05);
   SMBkgPlot__1->GetZaxis()->SetTitleFont(42);
   SMBkgPlot__1->Draw("HIST;E2");
   
   TH1D *SMBkgPlot__2 = new TH1D("SMBkgPlot__2","Title",6,0.0001,6.0001);
   SMBkgPlot__2->SetBinContent(1,1.75365);
   SMBkgPlot__2->SetBinContent(2,2.433873);
   SMBkgPlot__2->SetBinContent(3,1.852218);
   SMBkgPlot__2->SetBinContent(4,0.5294913);
   SMBkgPlot__2->SetBinError(1,0.9405259);
   SMBkgPlot__2->SetBinError(2,0.8714829);
   SMBkgPlot__2->SetBinError(3,0.7889607);
   SMBkgPlot__2->SetBinError(4,0.3094605);
   SMBkgPlot__2->SetEntries(148);
   SMBkgPlot__2->SetStats(0);
   SMBkgPlot__2->SetLineWidth(7);

   ci = TColor::GetColor("#ff0000");
   SMBkgPlot__2->SetMarkerColor(ci);
   SMBkgPlot__2->SetMarkerStyle(20);
   SMBkgPlot__2->SetMarkerSize(1e-09);
   SMBkgPlot__2->GetXaxis()->SetRange(1,6);
   SMBkgPlot__2->GetXaxis()->SetLabelFont(42);
   SMBkgPlot__2->GetXaxis()->SetLabelSize(0.05);
   SMBkgPlot__2->GetXaxis()->SetTitleSize(0.05);
   SMBkgPlot__2->GetXaxis()->SetTitleOffset(1.4);
   SMBkgPlot__2->GetXaxis()->SetTitleFont(42);
   SMBkgPlot__2->GetYaxis()->SetLabelFont(42);
   SMBkgPlot__2->GetYaxis()->SetLabelSize(0.05);
   SMBkgPlot__2->GetYaxis()->SetTitleSize(0.05);
   SMBkgPlot__2->GetYaxis()->SetTitleOffset(1.4);
   SMBkgPlot__2->GetYaxis()->SetTitleFont(42);
   SMBkgPlot__2->GetZaxis()->SetLabelFont(42);
   SMBkgPlot__2->GetZaxis()->SetLabelSize(0.05);
   SMBkgPlot__2->GetZaxis()->SetTitleSize(0.05);
   SMBkgPlot__2->GetZaxis()->SetTitleFont(42);
   SMBkgPlot__2->Draw("same;HIST");
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",6,0.0001,6.0001);
   hs_stack_1->SetMinimum(0.001052116);
   hs_stack_1->SetMaximum(4.208464);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);
   hs_stack_1->SetLineWidth(2);
   hs_stack_1->SetMarkerStyle(20);
   hs_stack_1->SetMarkerSize(1.2);
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetLabelSize(0.05);
   hs_stack_1->GetXaxis()->SetTitleSize(0.05);
   hs_stack_1->GetXaxis()->SetTitleOffset(1.4);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetLabelFont(42);
   hs_stack_1->GetYaxis()->SetLabelSize(0.05);
   hs_stack_1->GetYaxis()->SetTitleSize(0.05);
   hs_stack_1->GetYaxis()->SetTitleOffset(1.4);
   hs_stack_1->GetYaxis()->SetTitleFont(42);
   hs_stack_1->GetZaxis()->SetLabelFont(42);
   hs_stack_1->GetZaxis()->SetLabelSize(0.05);
   hs_stack_1->GetZaxis()->SetTitleSize(0.05);
   hs_stack_1->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_1);
   
   
   TH1D *DiBosonPlot_stack_1 = new TH1D("DiBosonPlot_stack_1","Title",6,0.0001,6.0001);
   DiBosonPlot_stack_1->SetBinContent(4,0.166023);
   DiBosonPlot_stack_1->SetBinError(4,0.166023);
   DiBosonPlot_stack_1->SetEntries(1);
   DiBosonPlot_stack_1->SetStats(0);

   ci = TColor::GetColor("#cc0000");
   DiBosonPlot_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#cc0000");
   DiBosonPlot_stack_1->SetLineColor(ci);
   DiBosonPlot_stack_1->SetMarkerStyle(20);
   DiBosonPlot_stack_1->SetMarkerSize(1.2);
   DiBosonPlot_stack_1->GetXaxis()->SetRange(1,6);
   DiBosonPlot_stack_1->GetXaxis()->SetLabelFont(42);
   DiBosonPlot_stack_1->GetXaxis()->SetLabelSize(0.05);
   DiBosonPlot_stack_1->GetXaxis()->SetTitleSize(0.05);
   DiBosonPlot_stack_1->GetXaxis()->SetTitleOffset(1.4);
   DiBosonPlot_stack_1->GetXaxis()->SetTitleFont(42);
   DiBosonPlot_stack_1->GetYaxis()->SetLabelFont(42);
   DiBosonPlot_stack_1->GetYaxis()->SetLabelSize(0.05);
   DiBosonPlot_stack_1->GetYaxis()->SetTitleSize(0.05);
   DiBosonPlot_stack_1->GetYaxis()->SetTitleOffset(1.4);
   DiBosonPlot_stack_1->GetYaxis()->SetTitleFont(42);
   DiBosonPlot_stack_1->GetZaxis()->SetLabelFont(42);
   DiBosonPlot_stack_1->GetZaxis()->SetLabelSize(0.05);
   DiBosonPlot_stack_1->GetZaxis()->SetTitleSize(0.05);
   DiBosonPlot_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(DiBosonPlot_stack_1,"");
   
   TH1D *ZjetsPlot_stack_2 = new TH1D("ZjetsPlot_stack_2","Title",6,0.0001,6.0001);
   ZjetsPlot_stack_2->SetBinContent(1,0.0704551);
   ZjetsPlot_stack_2->SetBinContent(2,0.1764891);
   ZjetsPlot_stack_2->SetBinContent(3,0.2006787);
   ZjetsPlot_stack_2->SetBinContent(4,0.04708892);
   ZjetsPlot_stack_2->SetBinError(1,0.04042947);
   ZjetsPlot_stack_2->SetBinError(2,0.1188509);
   ZjetsPlot_stack_2->SetBinError(3,0.1120923);
   ZjetsPlot_stack_2->SetBinError(4,0.02772876);
   ZjetsPlot_stack_2->SetEntries(20);
   ZjetsPlot_stack_2->SetStats(0);

   ci = TColor::GetColor("#0099ff");
   ZjetsPlot_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#0099ff");
   ZjetsPlot_stack_2->SetLineColor(ci);
   ZjetsPlot_stack_2->SetMarkerStyle(20);
   ZjetsPlot_stack_2->SetMarkerSize(1.2);
   ZjetsPlot_stack_2->GetXaxis()->SetRange(1,6);
   ZjetsPlot_stack_2->GetXaxis()->SetLabelFont(42);
   ZjetsPlot_stack_2->GetXaxis()->SetLabelSize(0.05);
   ZjetsPlot_stack_2->GetXaxis()->SetTitleSize(0.05);
   ZjetsPlot_stack_2->GetXaxis()->SetTitleOffset(1.4);
   ZjetsPlot_stack_2->GetXaxis()->SetTitleFont(42);
   ZjetsPlot_stack_2->GetYaxis()->SetLabelFont(42);
   ZjetsPlot_stack_2->GetYaxis()->SetLabelSize(0.05);
   ZjetsPlot_stack_2->GetYaxis()->SetTitleSize(0.05);
   ZjetsPlot_stack_2->GetYaxis()->SetTitleOffset(1.4);
   ZjetsPlot_stack_2->GetYaxis()->SetTitleFont(42);
   ZjetsPlot_stack_2->GetZaxis()->SetLabelFont(42);
   ZjetsPlot_stack_2->GetZaxis()->SetLabelSize(0.05);
   ZjetsPlot_stack_2->GetZaxis()->SetTitleSize(0.05);
   ZjetsPlot_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(ZjetsPlot_stack_2,"");
   
   TH1D *ttVPlot_stack_3 = new TH1D("ttVPlot_stack_3","Title",6,0.0001,6.0001);
   ttVPlot_stack_3->SetBinContent(1,0.1814873);
   ttVPlot_stack_3->SetBinContent(2,0.1234666);
   ttVPlot_stack_3->SetBinContent(3,0.0274734);
   ttVPlot_stack_3->SetBinContent(4,-0.01219733);
   ttVPlot_stack_3->SetBinError(1,0.1078822);
   ttVPlot_stack_3->SetBinError(2,0.1117621);
   ttVPlot_stack_3->SetBinError(3,0.1209429);
   ttVPlot_stack_3->SetBinError(4,0.02110657);
   ttVPlot_stack_3->SetEntries(49);
   ttVPlot_stack_3->SetStats(0);

   ci = TColor::GetColor("#009900");
   ttVPlot_stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#009900");
   ttVPlot_stack_3->SetLineColor(ci);
   ttVPlot_stack_3->SetMarkerStyle(20);
   ttVPlot_stack_3->SetMarkerSize(1.2);
   ttVPlot_stack_3->GetXaxis()->SetRange(1,6);
   ttVPlot_stack_3->GetXaxis()->SetLabelFont(42);
   ttVPlot_stack_3->GetXaxis()->SetLabelSize(0.05);
   ttVPlot_stack_3->GetXaxis()->SetTitleSize(0.05);
   ttVPlot_stack_3->GetXaxis()->SetTitleOffset(1.4);
   ttVPlot_stack_3->GetXaxis()->SetTitleFont(42);
   ttVPlot_stack_3->GetYaxis()->SetLabelFont(42);
   ttVPlot_stack_3->GetYaxis()->SetLabelSize(0.05);
   ttVPlot_stack_3->GetYaxis()->SetTitleSize(0.05);
   ttVPlot_stack_3->GetYaxis()->SetTitleOffset(1.4);
   ttVPlot_stack_3->GetYaxis()->SetTitleFont(42);
   ttVPlot_stack_3->GetZaxis()->SetLabelFont(42);
   ttVPlot_stack_3->GetZaxis()->SetLabelSize(0.05);
   ttVPlot_stack_3->GetZaxis()->SetTitleSize(0.05);
   ttVPlot_stack_3->GetZaxis()->SetTitleFont(42);
   hs->Add(ttVPlot_stack_3,"");
   
   TH1D *WjetsPlot_stack_4 = new TH1D("WjetsPlot_stack_4","Title",6,0.0001,6.0001);
   WjetsPlot_stack_4->SetBinContent(2,0.0633107);
   WjetsPlot_stack_4->SetBinContent(4,0.2553083);
   WjetsPlot_stack_4->SetBinError(2,0.03717439);
   WjetsPlot_stack_4->SetBinError(4,0.2553083);
   WjetsPlot_stack_4->SetEntries(5);
   WjetsPlot_stack_4->SetStats(0);

   ci = TColor::GetColor("#ff9900");
   WjetsPlot_stack_4->SetFillColor(ci);

   ci = TColor::GetColor("#ff9900");
   WjetsPlot_stack_4->SetLineColor(ci);
   WjetsPlot_stack_4->SetMarkerStyle(20);
   WjetsPlot_stack_4->SetMarkerSize(1.2);
   WjetsPlot_stack_4->GetXaxis()->SetRange(1,6);
   WjetsPlot_stack_4->GetXaxis()->SetLabelFont(42);
   WjetsPlot_stack_4->GetXaxis()->SetLabelSize(0.05);
   WjetsPlot_stack_4->GetXaxis()->SetTitleSize(0.05);
   WjetsPlot_stack_4->GetXaxis()->SetTitleOffset(1.4);
   WjetsPlot_stack_4->GetXaxis()->SetTitleFont(42);
   WjetsPlot_stack_4->GetYaxis()->SetLabelFont(42);
   WjetsPlot_stack_4->GetYaxis()->SetLabelSize(0.05);
   WjetsPlot_stack_4->GetYaxis()->SetTitleSize(0.05);
   WjetsPlot_stack_4->GetYaxis()->SetTitleOffset(1.4);
   WjetsPlot_stack_4->GetYaxis()->SetTitleFont(42);
   WjetsPlot_stack_4->GetZaxis()->SetLabelFont(42);
   WjetsPlot_stack_4->GetZaxis()->SetLabelSize(0.05);
   WjetsPlot_stack_4->GetZaxis()->SetTitleSize(0.05);
   WjetsPlot_stack_4->GetZaxis()->SetTitleFont(42);
   hs->Add(WjetsPlot_stack_4,"");
   
   TH1D *SingleTopPlot_stack_5 = new TH1D("SingleTopPlot_stack_5","Title",6,0.0001,6.0001);
   SingleTopPlot_stack_5->SetBinContent(2,0.2835271);
   SingleTopPlot_stack_5->SetBinError(2,0.143106);
   SingleTopPlot_stack_5->SetEntries(4);
   SingleTopPlot_stack_5->SetStats(0);

   ci = TColor::GetColor("#99ff99");
   SingleTopPlot_stack_5->SetFillColor(ci);

   ci = TColor::GetColor("#99ff99");
   SingleTopPlot_stack_5->SetLineColor(ci);
   SingleTopPlot_stack_5->SetMarkerStyle(20);
   SingleTopPlot_stack_5->SetMarkerSize(1.2);
   SingleTopPlot_stack_5->GetXaxis()->SetRange(1,6);
   SingleTopPlot_stack_5->GetXaxis()->SetLabelFont(42);
   SingleTopPlot_stack_5->GetXaxis()->SetLabelSize(0.05);
   SingleTopPlot_stack_5->GetXaxis()->SetTitleSize(0.05);
   SingleTopPlot_stack_5->GetXaxis()->SetTitleOffset(1.4);
   SingleTopPlot_stack_5->GetXaxis()->SetTitleFont(42);
   SingleTopPlot_stack_5->GetYaxis()->SetLabelFont(42);
   SingleTopPlot_stack_5->GetYaxis()->SetLabelSize(0.05);
   SingleTopPlot_stack_5->GetYaxis()->SetTitleSize(0.05);
   SingleTopPlot_stack_5->GetYaxis()->SetTitleOffset(1.4);
   SingleTopPlot_stack_5->GetYaxis()->SetTitleFont(42);
   SingleTopPlot_stack_5->GetZaxis()->SetLabelFont(42);
   SingleTopPlot_stack_5->GetZaxis()->SetLabelSize(0.05);
   SingleTopPlot_stack_5->GetZaxis()->SetTitleSize(0.05);
   SingleTopPlot_stack_5->GetZaxis()->SetTitleFont(42);
   hs->Add(SingleTopPlot_stack_5,"");
   
   TH1D *HiggsPlot_stack_6 = new TH1D("HiggsPlot_stack_6","Title",6,0.0001,6.0001);
   HiggsPlot_stack_6->SetStats(0);
   HiggsPlot_stack_6->SetFillColor(6);
   HiggsPlot_stack_6->SetLineColor(6);
   HiggsPlot_stack_6->SetMarkerStyle(20);
   HiggsPlot_stack_6->SetMarkerSize(1.2);
   HiggsPlot_stack_6->GetXaxis()->SetRange(1,6);
   HiggsPlot_stack_6->GetXaxis()->SetLabelFont(42);
   HiggsPlot_stack_6->GetXaxis()->SetLabelSize(0.05);
   HiggsPlot_stack_6->GetXaxis()->SetTitleSize(0.05);
   HiggsPlot_stack_6->GetXaxis()->SetTitleOffset(1.4);
   HiggsPlot_stack_6->GetXaxis()->SetTitleFont(42);
   HiggsPlot_stack_6->GetYaxis()->SetLabelFont(42);
   HiggsPlot_stack_6->GetYaxis()->SetLabelSize(0.05);
   HiggsPlot_stack_6->GetYaxis()->SetTitleSize(0.05);
   HiggsPlot_stack_6->GetYaxis()->SetTitleOffset(1.4);
   HiggsPlot_stack_6->GetYaxis()->SetTitleFont(42);
   HiggsPlot_stack_6->GetZaxis()->SetLabelFont(42);
   HiggsPlot_stack_6->GetZaxis()->SetLabelSize(0.05);
   HiggsPlot_stack_6->GetZaxis()->SetTitleSize(0.05);
   HiggsPlot_stack_6->GetZaxis()->SetTitleFont(42);
   hs->Add(HiggsPlot_stack_6,"");
   
   TH1D *ttbarPlot_stack_7 = new TH1D("ttbarPlot_stack_7","Title",6,0.0001,6.0001);
   ttbarPlot_stack_7->SetBinContent(1,1.501708);
   ttbarPlot_stack_7->SetBinContent(2,1.787079);
   ttbarPlot_stack_7->SetBinContent(3,1.624066);
   ttbarPlot_stack_7->SetBinContent(4,0.07326835);
   ttbarPlot_stack_7->SetBinError(1,0.9334431);
   ttbarPlot_stack_7->SetBinError(2,0.843211);
   ttbarPlot_stack_7->SetBinError(3,0.7715356);
   ttbarPlot_stack_7->SetBinError(4,0.04249027);
   ttbarPlot_stack_7->SetEntries(69);
   ttbarPlot_stack_7->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   ttbarPlot_stack_7->SetFillColor(ci);

   ci = TColor::GetColor("#ff6600");
   ttbarPlot_stack_7->SetLineColor(ci);
   ttbarPlot_stack_7->SetMarkerStyle(20);
   ttbarPlot_stack_7->SetMarkerSize(1.2);
   ttbarPlot_stack_7->GetXaxis()->SetRange(1,6);
   ttbarPlot_stack_7->GetXaxis()->SetLabelFont(42);
   ttbarPlot_stack_7->GetXaxis()->SetLabelSize(0.05);
   ttbarPlot_stack_7->GetXaxis()->SetTitleSize(0.05);
   ttbarPlot_stack_7->GetXaxis()->SetTitleOffset(1.4);
   ttbarPlot_stack_7->GetXaxis()->SetTitleFont(42);
   ttbarPlot_stack_7->GetYaxis()->SetLabelFont(42);
   ttbarPlot_stack_7->GetYaxis()->SetLabelSize(0.05);
   ttbarPlot_stack_7->GetYaxis()->SetTitleSize(0.05);
   ttbarPlot_stack_7->GetYaxis()->SetTitleOffset(1.4);
   ttbarPlot_stack_7->GetYaxis()->SetTitleFont(42);
   ttbarPlot_stack_7->GetZaxis()->SetLabelFont(42);
   ttbarPlot_stack_7->GetZaxis()->SetLabelSize(0.05);
   ttbarPlot_stack_7->GetZaxis()->SetTitleSize(0.05);
   ttbarPlot_stack_7->GetZaxis()->SetTitleFont(42);
   hs->Add(ttbarPlot_stack_7,"");
   hs->Draw("same;hist");
   
   TH1D *signalPlot__3 = new TH1D("signalPlot__3","Title",6,0.0001,6.0001);
   signalPlot__3->SetBinContent(2,7.622185);
   signalPlot__3->SetBinContent(3,3.532408);
   signalPlot__3->SetBinContent(4,1.018742);
   signalPlot__3->SetBinError(2,1.923378);
   signalPlot__3->SetBinError(3,1.358514);
   signalPlot__3->SetBinError(4,0.7228867);
   signalPlot__3->SetEntries(25);
   signalPlot__3->SetStats(0);

   ci = TColor::GetColor("#ff00ff");
   signalPlot__3->SetLineColor(ci);
   signalPlot__3->SetLineStyle(2);
   signalPlot__3->SetLineWidth(3);
   signalPlot__3->SetMarkerStyle(20);
   signalPlot__3->SetMarkerSize(1.2);
   signalPlot__3->GetXaxis()->SetRange(1,6);
   signalPlot__3->GetXaxis()->SetLabelFont(42);
   signalPlot__3->GetXaxis()->SetLabelSize(0.05);
   signalPlot__3->GetXaxis()->SetTitleSize(0.05);
   signalPlot__3->GetXaxis()->SetTitleOffset(1.4);
   signalPlot__3->GetXaxis()->SetTitleFont(42);
   signalPlot__3->GetYaxis()->SetLabelFont(42);
   signalPlot__3->GetYaxis()->SetLabelSize(0.05);
   signalPlot__3->GetYaxis()->SetTitleSize(0.05);
   signalPlot__3->GetYaxis()->SetTitleOffset(1.4);
   signalPlot__3->GetYaxis()->SetTitleFont(42);
   signalPlot__3->GetZaxis()->SetLabelFont(42);
   signalPlot__3->GetZaxis()->SetLabelSize(0.05);
   signalPlot__3->GetZaxis()->SetTitleSize(0.05);
   signalPlot__3->GetZaxis()->SetTitleFont(42);
   signalPlot__3->Draw("SAME;HIST");
   TLatex *   tex = new TLatex(0.195,0.87,"#sqrt{s} = 13 TeV, 79.9 fb^{-1}");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.195,0.92,"#it{#bf{ATLAS}} Internal");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.195,0.82,"SR_SRB_original_N-1");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.59,0.68,0.99,0.94,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("DataPlot","Data","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SMBkgPlot","SM Total","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(7);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ttbarPlot_stack_7","t#bar{t}","F");

   ci = TColor::GetColor("#00ccff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff6600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("WjetsPlot_stack_4","W + Jets","F");

   ci = TColor::GetColor("#ff9900");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff9900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SingleTopPlot_stack_5","Single t","F");

   ci = TColor::GetColor("#99ff99");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#99ff99");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ZjetsPlot_stack_2","Z + Jets","F");

   ci = TColor::GetColor("#0099ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#0099ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ttVPlot_stack_3","t#bar{t}+V","F");

   ci = TColor::GetColor("#009900");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("DiBosonPlot_stack_1","DiBoson","F");

   ci = TColor::GetColor("#cc0000");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#cc0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("HiggsPlot_stack_6","Higgs","F");
   entry->SetFillColor(6);
   entry->SetFillStyle(1001);
   entry->SetLineColor(6);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("signalPlot","(m_{#tilde{b}}, m_{#tilde{#chi}_{2}^{0}}, m_{#tilde{#chi}_{1}^{0}}) = (700, 580, 450)GeV","L");

   ci = TColor::GetColor("#ff00ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);

   TLine *line1 = new TLine(3.5,0,3.5,10);
   line1->SetLineColor(kBlack);
   line1->SetLineWidth(5);
   
   TArrow *arrow = new TArrow(3.50,10,3.2,10,0.01,">");
   arrow->SetLineWidth(5);
   line1->Draw();
   arrow->Draw();

   leg->Draw();
   pad1->Modified();
   Canvas1->cd();
  
// ------------>Primitives in pad: pad2
   TPad *pad2 = new TPad("pad2", "pad2",0,0.065,1,0.3);
   pad2->Draw();
   pad2->cd();
   pad2->Range(-1.21509,-1.633333,6.379847,2.2);
   pad2->SetFillColor(0);
   pad2->SetBorderMode(0);
   pad2->SetBorderSize(2);
   pad2->SetTickx(1);
   pad2->SetTicky(1);
   pad2->SetLeftMargin(0.16);
   pad2->SetRightMargin(0.05);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.4);
   pad2->SetFrameBorderMode(0);
   pad2->SetFrameBorderMode(0);
   
   TH1D *SMBkgPlot__4 = new TH1D("SMBkgPlot__4","Title",6,0.0001,6.0001);
   SMBkgPlot__4->SetBinContent(1,1);
   SMBkgPlot__4->SetBinContent(2,1);
   SMBkgPlot__4->SetBinContent(3,1);
   SMBkgPlot__4->SetBinContent(4,1);
   SMBkgPlot__4->SetBinError(1,0.7584777);
   SMBkgPlot__4->SetBinError(2,0.5063794);
   SMBkgPlot__4->SetBinError(3,0.6023906);
   SMBkgPlot__4->SetBinError(4,0.8265352);
   SMBkgPlot__4->SetMinimum(-0.1);
   SMBkgPlot__4->SetMaximum(2.2);
   SMBkgPlot__4->SetEntries(8.520866);
   SMBkgPlot__4->SetStats(0);
   SMBkgPlot__4->SetFillColor(1);
   SMBkgPlot__4->SetFillStyle(3013);

   ci = TColor::GetColor("#ff0000");
   SMBkgPlot__4->SetMarkerColor(ci);
   SMBkgPlot__4->SetMarkerStyle(20);
   SMBkgPlot__4->SetMarkerSize(1e-05);
   SMBkgPlot__4->GetXaxis()->SetTitle("SRB1_DRmin2");
   SMBkgPlot__4->GetXaxis()->SetRange(1,6);
   SMBkgPlot__4->GetXaxis()->SetLabelFont(42);
   SMBkgPlot__4->GetXaxis()->SetLabelSize(0.12);
   SMBkgPlot__4->GetXaxis()->SetTitleSize(0.12);
   SMBkgPlot__4->GetXaxis()->SetTitleFont(42);
   SMBkgPlot__4->GetYaxis()->SetTitle("Data / SM");
   SMBkgPlot__4->GetYaxis()->CenterTitle(true);
   SMBkgPlot__4->GetYaxis()->SetNdivisions(603);
   SMBkgPlot__4->GetYaxis()->SetLabelFont(42);
   SMBkgPlot__4->GetYaxis()->SetLabelSize(0.12);
   SMBkgPlot__4->GetYaxis()->SetTitleSize(0.12);
   SMBkgPlot__4->GetYaxis()->SetTitleOffset(0.5);
   SMBkgPlot__4->GetYaxis()->SetTitleFont(42);
   SMBkgPlot__4->GetZaxis()->SetLabelFont(42);
   SMBkgPlot__4->GetZaxis()->SetLabelSize(0.05);
   SMBkgPlot__4->GetZaxis()->SetTitleSize(0.05);
   SMBkgPlot__4->GetZaxis()->SetTitleFont(42);
   SMBkgPlot__4->Draw("E2");
   TLine *line = new TLine(0.0001,1,6.0001,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->Draw();
   pad2->Modified();
   Canvas1->cd();
   Canvas1->Modified();
   Canvas1->cd();
   Canvas1->SetSelected(Canvas1);
}
