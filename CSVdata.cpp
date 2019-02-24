//-------------------------------------------------------------------------

#include "CSVdata.h"
#include <assert.h>
#include <iosfwd>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>

//-------------------------------------------------------------------------


namespace CSVdata
{
    CSVDataReader::CSVDataReader(std::string const& filePath, std::string const& fileName)
    {
        assert( !filePath.empty() );
        m_filePath = filePath;
        m_fileName = fileName;
        
        for (int i = 0; i < NumCoins; i++)
        {
            m_meanPrice.push_back(0.0);
            m_minPrice.push_back(0.0);
            m_maxPrice.push_back(0.0);
            m_SD.push_back(0.0);
            m_variance.push_back(0.0);
            
            std::vector<double> dummy;
            
            
            for (int j = 0; j < 300; j++)
            {
                m_MeanStore.push_back(dummy);
                m_MeanStore[i].push_back(0.0);
                
                m_PastPrices.push_back(dummy);
                m_PastPrices[i].push_back(0.0);
            }
            m_MeanStoreCntr.push_back(0.0);
            m_PastPricesCntr.push_back(0.0); 
        }
        std::cout << "Finished Init" << std::endl;
    }

    bool CSVDataReader::RunProgram()
    {
        std::cout << "Running Program" << std::endl; 
        assert( !m_filePath.empty() );

        std::fstream inputFile;
        inputFile.open( m_filePath, std::ios::in );
        std::string data;
        
        if ( inputFile.is_open() )
        {
            getline(inputFile, data); // clear header
            data = "0";
            std::vector<DataIn> SavedFile;
            
            while (getline(inputFile, data)) 
            {
                std::istringstream s(data);
                std::string number;
                int cnt = 0;
                DataIn tempRow = DataIn();
                int numCntr = 0;
                
                while(getline(s, number, ','))
                {
                    if (number != "")
                    {
                        double tempNum = std::stod(number);
                        ++numCntr;
                        switch (cnt)
                        {
                            case ETH_Ask:
                                tempRow.ETH_Ask = tempNum;
                                //std::cout << tempNum << std::endl;
                                break;
                            
                            case ETH_Bid:
                                tempRow.ETH_Bid = tempNum;
                                break;
                            
                            case ETH_Last:
                                tempRow.ETH_Last = tempNum;
                                break;
                            
                            case BTC_Ask:
                                tempRow.BTC_Ask = tempNum;
                                break;
                            
                            case BTC_Bid:
                                tempRow.BTC_Bid = tempNum;
                                break;
                            
                            case BTC_Last:
                                tempRow.BTC_Last = tempNum;
                                break;
                            
                            case BCH_Ask:
                                tempRow.BCH_Ask = tempNum;
                                break;
                            
                            case BCH_Bid:
                                tempRow.BCH_Bid = tempNum;
                                break;
                            
                            case BCH_Last:
                                tempRow.BCH_Last = tempNum;
                                break;
                            
                            case LTC_Ask:
                                tempRow.LTC_Ask = tempNum;
                                break;
                            
                            case LTC_Bid:
                                tempRow.LTC_Bid = tempNum;
                                break;
                            
                            case LTC_Last:
                                tempRow.LTC_Last = tempNum;
                                break;
                            
                            case BSV_Ask:
                                tempRow.BSV_Ask = tempNum;
                                break;
                            
                            case BSV_Bid:
                                tempRow.BSV_Bid = tempNum;
                                break;
                            
                            case BSV_Last:
                                tempRow.BSV_Last = tempNum;
                                break;
                            
                            case XMR_Ask:
                                tempRow.XMR_Ask = tempNum;
                                break;
                            
                            case XMR_Bid:
                                tempRow.XMR_Bid = tempNum;
                                break;
                            
                            case XMR_Last:
                                tempRow.XMR_Last = tempNum;
                                break;
                            
                            default:
                                break;
                        }
                        ++cnt;
                    }
                    
                
                }
                if (numCntr == InputDataSize)
                {
                    SavedFile.push_back(tempRow);
                }
                else
                {
                    std::cout << "Invalid Line format" << std::endl;
                }
                
            }
            inputFile.close();
            
            CalcStats(SavedFile); 
        }
        else
        {
            std::cout << "Error Opening Input File: " << m_filePath << std::endl;
            return false;
        }
        return true;
    }

    
    void CSVDataReader::CalcStats(std::vector<DataIn> input)
    {
        std::vector<double> tempNNdata;
        
        std::vector<double> ETHPrices;
        std::vector<double> CalcedETH;
        
        std::vector<double> BTCPrices;
        std::vector<double> CalcedBTC;
        
        std::vector<double> BCHPrices;
        std::vector<double> CalcedBCH;
        
        std::vector<double> LTCPrices;
        std::vector<double> CalcedLTC;
        
        std::vector<double> BSVPrices;
        std::vector<double> CalcedBSV;
        
        std::vector<double> XMRPrices;
        std::vector<double> CalcedXMR;
        
        for (int j=0; j < 6; j++)
        {
            ETHPrices.push_back(0);
            BTCPrices.push_back(0);
            BCHPrices.push_back(0);
            LTCPrices.push_back(0);
            BSVPrices.push_back(0);
            XMRPrices.push_back(0);
        }
        
        // === Open output File
        //std::string oFileName = m_filename.substr(0, m_filename.find_last_of("\\/"));
        
        std::string oFileName = m_fileName;
        
        std::string s1 = "Output_";
        
        oFileName.insert(0, s1);
        
        size_t lastindex = oFileName.find_last_of("."); 
        oFileName = oFileName.substr(0, lastindex);
        oFileName.append(".dat");
        
        std::ofstream outputFile;
        outputFile.open( oFileName, std::ios::out );
        
        if ( outputFile.is_open() )
        {
        
            for (int i=1; i<(input.size()-1); i++)
            {
                //++++ Calculate ETH dataSet ++++
                ETHPrices[0] = input[i].ETH_Ask;
                ETHPrices[1] = input[i].ETH_Bid;
                ETHPrices[2] = input[i].ETH_Last;
                ETHPrices[3] = input[i+1].ETH_Ask; // Future Asking Price  
                ETHPrices[4] = input[i+1].ETH_Bid; // Future Bid Price
                CalcedETH = CalcCoinStats(ETHPrices, ETH);
                tempNNdata.insert(tempNNdata.end(), CalcedETH.begin(), CalcedETH.end());
                //++++ Calculate BTC dataSet ++++
                BTCPrices[0] = input[i].BTC_Ask;
                BTCPrices[1] = input[i].BTC_Bid;
                BTCPrices[2] = input[i].BTC_Last;
                BTCPrices[3] = input[i+1].BTC_Ask; // Future Asking Price  
                BTCPrices[4] = input[i+1].BTC_Bid; // Future Bid Price
                CalcedBTC = CalcCoinStats(BTCPrices, BTC);
                tempNNdata.insert(tempNNdata.end(), CalcedBTC.begin(),  CalcedBTC.end());
                //++++ Calculate BCH dataSet ++++
                BCHPrices[0] = input[i].BCH_Ask;
                BCHPrices[1] = input[i].BCH_Bid;
                BCHPrices[2] = input[i].BCH_Last;
                BCHPrices[3] = input[i+1].BCH_Ask; // Future Asking Price  
                BCHPrices[4] = input[i+1].BCH_Bid; // Future Bid Price
                CalcedBCH = CalcCoinStats(BCHPrices, BCH);
                tempNNdata.insert(tempNNdata.end(), CalcedBCH.begin(),  CalcedBCH.end());
                //++++ Calculate LTC dataSet ++++
                LTCPrices[0] = input[i].LTC_Ask;
                LTCPrices[1] = input[i].LTC_Bid;
                LTCPrices[2] = input[i].LTC_Last;
                LTCPrices[3] = input[i+1].LTC_Ask; // Future Asking Price  
                LTCPrices[4] = input[i+1].LTC_Bid; // Future Bid Price
                CalcedLTC = CalcCoinStats(LTCPrices, LTC);
                tempNNdata.insert(tempNNdata.end(), CalcedLTC.begin(), CalcedLTC.end());
                //++++ Calculate BSV dataSet ++++
                BSVPrices[0] = input[i].BSV_Ask;
                BSVPrices[1] = input[i].BSV_Bid;
                BSVPrices[2] = input[i].BSV_Last;
                BSVPrices[3] = input[i+1].BSV_Ask; // Future Asking Price  
                BSVPrices[4] = input[i+1].BSV_Bid; // Future Bid Price
                CalcedBSV = CalcCoinStats(BSVPrices, BSV);
                tempNNdata.insert(tempNNdata.end(), CalcedBSV.begin(),  CalcedBSV.end());
                //++++ Calculate XMR dataSet ++++
                XMRPrices[0] = input[i].XMR_Ask;
                XMRPrices[1] = input[i].XMR_Bid;
                XMRPrices[2] = input[i].XMR_Last;
                XMRPrices[3] = input[i+1].XMR_Ask; // Future Asking Price  
                XMRPrices[4] = input[i+1].XMR_Bid; // Future Bid Price
                CalcedXMR = CalcCoinStats(XMRPrices, XMR);
                tempNNdata.insert(tempNNdata.end(), CalcedXMR.begin(),                      CalcedXMR.end());
                
                // Write NNdata
                WriteNNdata(tempNNdata, outputFile);
                tempNNdata.clear();
            }
        }
        else
        {
            std::cout << "Error: Output file failed to open, "<< oFileName << std::endl;
        }
        
    }
    
    std::vector<double> CSVDataReader::CalcCoinStats(std::vector<double> inputPrice, Coins coin)
    {
        std::vector<double> output;    
        
        double AskPrice = inputPrice[0];
        double BidPrice = inputPrice[1];
        double LastPrice = inputPrice[2];
        double MeanPrice = 0;
        double SD = 0;
        double Variance = 0;
        double minPrice = 0;
        double maxPrice = 0;
        double priceDelta = 0;
        double FutureAskingPrice = inputPrice[3];
        double FutureBidPrice = inputPrice[4];
        
        //========== Do Math ===============
        //==================================
        
        if (AskPrice > m_maxPrice[coin])
        {
            maxPrice = AskPrice;
            m_maxPrice[coin] = maxPrice;
        }
        else
        {
            maxPrice = m_maxPrice[coin];
        }
        
        if ((AskPrice < m_minPrice[coin]) || (m_minPrice[coin] == 0))
        {
            minPrice = AskPrice;
            m_minPrice[coin] = minPrice;
        }
        else
        {
            minPrice = m_minPrice[coin];
        }
        
        // === Add price to price storeage ===
        m_PastPrices[coin][m_PastPricesCntr[coin]] = AskPrice;
        
        
        if (m_PastPricesCntr[coin] == 299)
        {
            m_PastPricesCntr[coin] = 0;
        }
        else
        {
            m_PastPricesCntr[coin] = m_PastPricesCntr[coin] + 1;
        }
        
        // === Get Average from price storage ===
        double PriceSum = 0;
        int SumCntr = 0;
        for (int i = 0; i < m_PastPrices[coin].size(); i++)
        {
            if (m_PastPrices[coin][i] != 0)
            {
                PriceSum = PriceSum + m_PastPrices[coin][i];
                ++SumCntr;
            }
        }
        
        m_meanPrice[coin] = PriceSum / SumCntr;
        MeanPrice = m_meanPrice[coin];
        
        // === Add mean price to mean storeage ===
        m_MeanStore[coin][m_MeanStoreCntr[coin]] = m_meanPrice[coin];
        if (m_MeanStoreCntr[coin] == 299)
        {
            m_MeanStoreCntr[coin] = 0;
        }
        else
        {
            m_MeanStoreCntr[coin] = m_MeanStoreCntr[coin] + 1;
        }
        
        CalcSD(coin);
        
        priceDelta = sqrt(pow((AskPrice - m_MeanStore[coin][m_MeanStoreCntr[coin] - 1]),2));
        
        SD = m_SD[coin];
        Variance = m_variance[coin];
        //==================================
        //==================================
        
        output.push_back(AskPrice);
        output.push_back(BidPrice);
        output.push_back(LastPrice);
        output.push_back(MeanPrice);
        output.push_back(SD);
        output.push_back(Variance);
        output.push_back(minPrice);
        output.push_back(maxPrice);
        output.push_back(priceDelta);
        output.push_back(FutureAskingPrice);
        output.push_back(FutureBidPrice);
        
        return output;
    }
    
    void CSVDataReader::CalcSD(Coins coin)
    {
        double Average = m_meanPrice[coin];
        double sqrSum = 0;
        int sqrSumCntr = 0;
        
        for (int i =0; i< m_PastPrices[coin].size(); i++)
        {
            if (m_PastPrices[coin][i] != 0)
            {
                sqrSum = sqrSum + pow((m_PastPrices[coin][i] - Average), 2);
                ++sqrSumCntr;
            }
        }
        //std::cout << sqrSum/(sqrSumCntr - 1) << std::endl;
        //std::cout << sqrSum << std::endl;
        
        m_variance[coin] = sqrSum/(sqrSumCntr - 1);
        
        m_SD[coin] = sqrt(m_variance[coin]);
    }
    
    void CSVDataReader::WriteNNdata( std::vector<double> data, std::ofstream &fout)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (i < (data.size() - 1))
            {
                fout << data[i] << ",";
            }
            else
            {
                fout << data[i] << "\n";
            }
        }
    }
    
}






